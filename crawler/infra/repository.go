package infra

import (
	"context"
	"fmt"
	"log"
	"os"
	"path/filepath"
	"strings"
	"time"

	model "github.com/matumoto1234/cp-crawler/domain/model"
	"github.com/matumoto1234/cp-crawler/domain/service"
	"github.com/pkg/errors"
)

type Git interface {
	Add(path string) error
	Commit(commitMsg string, dateTime time.Time) error
	Push() error
}

type FileSystem interface {
	FileName(lang, submissionID string) (string, error)
	Dir(siteID model.Site, problemID, contestID string) (string, error)
	WriteFile(dir, fileName string, content []byte) error
}

type submissionRepositoryImpl struct {
	g Git
	f FileSystem
	s service.Scraper
	m service.RepositoryManager
}

func NewSubmissionRepository(g Git, f FileSystem, s service.Scraper, m service.RepositoryManager) *submissionRepositoryImpl {
	return &submissionRepositoryImpl{
		g: g,
		f: f,
		s: s,
		m: m,
	}
}

// Save() : 提出情報を保存する
func (sr submissionRepositoryImpl) Save(ctx context.Context, s *model.Submission) error {
	exists, err := sr.m.Exists(ctx, s)
	if err != nil {
		return err
	}

	if exists {
		return nil
	}

	if err := sr.writeAndCommit(ctx, s); err != nil {
		return err
	}

	if err := sr.g.Push(); err != nil {
		return err
	}

	return nil
}

// SaveAll() : 提出情報リストを保存する
func (sr submissionRepositoryImpl) SaveAll(ctx context.Context, submissionList []*model.Submission) error {
	saved := false
	for _, s := range submissionList {
		exists, err := sr.m.Exists(ctx, s)
		if err != nil {
			return err
		}

		if exists {
			continue
		}

		if err := sr.writeAndCommit(ctx, s); err != nil {
			return err
		}
		saved = true
	}

	if saved {
		if err := sr.g.Push(); err != nil {
			return err
		}
	}

	return nil
}

// writeAndCommit() : 提出情報を保存し、Add, Commitを行う
// すでに保存済みの提出情報の場合はtrue,nilを返す
func (sr submissionRepositoryImpl) writeAndCommit(ctx context.Context, s *model.Submission) error {
	dir, err := sr.f.Dir(s.SiteID, s.ProblemID, s.ContestID)
	if err != nil {
		return err
	}

	header, err := header(s)
	if err != nil {
		return err
	}

	code, err := sr.s.SourceCode(ctx, s.SubmissionURL)
	if err != nil {
		return err
	}

	fileName, err := sr.f.FileName(s.Language, s.SubmissionID)
	if err != nil {
		return err
	}

	content := []byte(header + "\n" + code)

	if err := sr.f.WriteFile(dir, fileName, content); err != nil {
		return err
	}

	path := filepath.Join(dir, fileName)

	logInfo := log.New(os.Stdout, "[INFO] ", log.LstdFlags)
	logInfo.Println("write " + path)

	if err := sr.g.Add(path); err != nil {
		return err
	}

	if err := sr.g.Commit("add "+path, s.SubmittedAt); err != nil {
		return err
	}

	return nil
}

// header() : ソースコードファイルの先頭にコメントとして残すヘッダーを作成する
// URLとソースコードを紐付けて保存したい(システム要件)→DBとしてGitを使う以上、同ファイル内にURLを残す必要がある(infra層の責務)
func header(s *model.Submission) (string, error) {
	headerComment := fmt.Sprintf(" detail: %s ", s.SubmissionURL)

	header, err := commentOut(s.Language, headerComment)
	if err != nil {
		return "", err
	}

	header = strings.Trim(header, " ")

	return header, nil
}

// commentOut() : 1行のコメントアウトを行う
func commentOut(lang, line string) (string, error) {
	commentList := []struct {
		lang   string
		prefix string
		suffix string
	}{
		{lang: "Awk", prefix: "#", suffix: ""},
		{lang: "C#", prefix: "//", suffix: ""},
		{lang: "C++", prefix: "//", suffix: ""},
		{lang: "Bash", prefix: "#", suffix: ""},
		{lang: "Brainfuck", prefix: "#", suffix: ""},
		{lang: "COBOL", prefix: "*", suffix: ""},
		{lang: "Clojure", prefix: ";", suffix: ""},
		{lang: "Lisp", prefix: ";", suffix: ""},
		{lang: "Crystal", prefix: "#", suffix: ""},
		{lang: "Fortran", prefix: "*", suffix: ""},
		{lang: "Go", prefix: "//", suffix: ""},
		{lang: "Haskell", prefix: "--", suffix: ""},
		{lang: "JavaScript", prefix: "//", suffix: ""},
		{lang: "Java", prefix: "//", suffix: ""},
		{lang: "Julia", prefix: "#", suffix: ""},
		{lang: "Kotlin", prefix: "//", suffix: ""},
		{lang: "MoonScript", prefix: "--", suffix: ""},
		{lang: "Nim", prefix: "#", suffix: ""},
		{lang: "OCaml", prefix: "*", suffix: "*"},
		{lang: "Objective", prefix: "//", suffix: ""},
		{lang: "Octave", prefix: "%{", suffix: "%}"},
		{lang: "PHP", prefix: "<!--", suffix: "--?"},
		{lang: "Pascal", prefix: "//", suffix: ""},
		{lang: "Perl", prefix: "#", suffix: ""},
		{lang: "Py", prefix: "#", suffix: ""},
		{lang: "Ruby", prefix: "#", suffix: ""},
		{lang: "Rust", prefix: "//", suffix: ""},
		{lang: "Scala", prefix: "//", suffix: ""},
		{lang: "Scheme", prefix: ";", suffix: ""},
		{lang: "Sed", prefix: "//", suffix: ""},
		{lang: "Swift", prefix: "//", suffix: ""},
		{lang: "Text", prefix: "//", suffix: ""},
		{lang: "TypeScript", prefix: "//", suffix: ""},
		{lang: "Unlambda", prefix: "#", suffix: ""},
		{lang: "Basic", prefix: "'", suffix: ""},
		{lang: "ML", prefix: "*", suffix: "*"},
		{lang: "F#", prefix: "//", suffix: ""},
		{lang: "C", prefix: "//", suffix: ""},
		{lang: "D", prefix: "//", suffix: ""},
	}

	for _, v := range commentList {
		if strings.Contains(lang, v.lang) {
			return v.prefix + line + v.suffix, nil
		}
	}

	return "", errors.New(fmt.Sprintf("%s is not supported.", lang))
}
