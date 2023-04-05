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
	Dir(siteID model.Site, problemID string) (string, error)
	WriteFile(dir, fileName string, content []byte) error
}

type submissionRepositoryImpl struct {
	g Git
	f FileSystem
	s service.Scraper
}

func NewSubmissionRepository(g Git, f FileSystem, s service.Scraper) *submissionRepositoryImpl {
	return &submissionRepositoryImpl{
		g: g,
		f: f,
		s: s,
	}
}

// Save() : 提出情報を保存する
func (sr submissionRepositoryImpl) Save(ctx context.Context, s *model.Submission) error {
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
	for _, s := range submissionList {
		if err := sr.writeAndCommit(ctx, s); err != nil {
			return err
		}
	}

	if err := sr.g.Push(); err != nil {
		return err
	}

	return nil
}

// writeAndCommit() : 提出情報を保存し、Add, Commitを行う
func (sr submissionRepositoryImpl) writeAndCommit(ctx context.Context, s *model.Submission) error {
	dir, err := sr.f.Dir(s.SiteID, s.ProblemID)
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
	type affix struct {
		prefix string
		suffix string
	}

	langToComment := map[string]affix{
		"Awk":        {"#", ""},
		"C#":         {"//", ""},
		"C++":        {"//", ""},
		"Bash":       {"#", ""},
		"Brainfuck":  {"#", ""},
		"COBOL":      {"*", ""},
		"Clojure":    {";", ""},
		"Lisp":       {";", ""},
		"Crystal":    {"#", ""},
		"Fortran":    {"*", ""},
		"Go":         {"//", ""},
		"Haskell":    {"--", ""},
		"JavaScript": {"//", ""},
		"Java":       {"//", ""},
		"Julia":      {"#", ""},
		"Kotlin":     {"//", ""},
		"MoonScript": {"--", ""},
		"Nim":        {"#", ""},
		"OCaml":      {"*", "*"},
		"Objective":  {"//", ""},
		"Octave":     {"%{", "%}"},
		"PHP":        {"<!--", "--?"},
		"Pascal":     {"//", ""},
		"Perl":       {"#", ""},
		"Py":         {"#", ""},
		"Ruby":       {"#", ""},
		"Rust":       {"//", ""},
		"Scala":      {"//", ""},
		"Scheme":     {";", ""},
		"Sed":        {"//", ""}, // inaccurate
		"Swift":      {"//", ""},
		"Text":       {"//", ""}, // inaccurate
		"TypeScript": {"//", ""},
		"Unlambda":   {"#", ""},
		"Basic":      {"'", ""},
		"ML":         {"*", "*"},
		"F#":         {"//", ""},
		"C":          {"//", ""},
		"D":          {"//", ""},
	}

	for key, affix := range langToComment {
		if strings.Contains(lang, key) {
			return affix.prefix + line + affix.suffix, nil
		}
	}

	return "", errors.New(fmt.Sprintf("%s is not supported.", lang))
}
