package db

import (
	"context"
	"fmt"
	"os"
	"path/filepath"
	"strings"

	model "github.com/matumoto1234/cp-crawler/domain/model"
	"github.com/pkg/errors"
)

type affix struct {
	prefix string
	suffix string
}

type Writer struct {
}

func NewWriter() *Writer {
	return &Writer{}
}

func (w *Writer) Do(ctx context.Context, s *model.Submission) error {
	path, err := w.DestinationPath(s)
	if err != nil {
		return err
	}

	header, err := header(s)
	if err != nil {
		return err
	}

	content := []byte(header + "\n" + s.SourceCode)

	if err := os.MkdirAll(path, 0755); err != nil {
		return errors.WithStack(err)
	}

	fileName, err := w.FileName(s)
	if err != nil {
		return err
	}

	filePath := path + fileName

	if err := os.WriteFile(filePath, content, 0755); err != nil {
		return errors.WithStack(err)
	}

	return nil
}

// FileName() : ファイル名を返す
func (w *Writer) FileName(s *model.Submission) (string, error) {
	// toExtension() : 言語名を元に拡張子を返す
	toExtension := func(lang string) (string, error) {
		langToExtension := map[string]string{
			"Awk":        "awk",
			"C#":         "cs",
			"C++":        "cpp",
			"Bash":       "sh",
			"Brainfuck":  "bf",
			"COBOL":      "cobol",
			"Clojure":    "clj",
			"Lisp":       "lisp",
			"Crystal":    "cr",
			"Fortran":    "f",
			"Go":         "go",
			"Haskell":    "hs",
			"JavaScript": "js",
			"Java":       "java",
			"Julia":      "jl",
			"Kotlin":     "kt",
			"MoonScript": "moon",
			"Nim":        "nim",
			"OCaml":      "ml",
			"Objective":  "m",
			"Octave":     "m",
			"PHP":        "php",
			"Pascal":     "pas",
			"Perl":       "pl",
			"Py":         "py",
			"Ruby":       "rb",
			"Rust":       "rs",
			"Scala":      "scala",
			"Scheme":     "ss",
			"Sed":        "sed",
			"Swift":      "swift",
			"Text":       "txt",
			"TypeScript": "ts",
			"Unlambda":   "unl",
			"Basic":      "vb",
			"ML":         "sml",
			"F#":         "fs",
			"C":          "c",
			"D":          "d",
		}

		for key, ext := range langToExtension {
			if strings.Contains(lang, key) {
				return ext, nil
			}
		}
		return "", errors.New(fmt.Sprintf("GetExtension: %v is not supported.", lang))
	}

	ext, err := toExtension(s.Language)
	if err != nil {
		return "", err
	}

	return fmt.Sprintf("%v.%v", s.SubmissionID, ext), nil
}

// DestinationPath() : 保存先ファイルパスを返す
func (w *Writer) DestinationPath(s *model.Submission) (string, error) {
	dir := filepath.Join(s.SiteID.String(), s.ProblemID)

	// crawlerの親に作りたいので../を先頭に追加
	return filepath.Join("../", dir), nil
}

// header() : ソースコードファイルの先頭にコメントとして残すヘッダーを作成する
// URLとソースコードを紐付けて保存したい(システム要件)→DBとしてGitを使う以上、同ファイル内にURLを残す必要がある(infra層の責務)
func header(s *model.Submission) (string, error) {
	headerComment := fmt.Sprintf(" detail: %v ", s.SubmissionURL)

	commentOut := func(lang, line string) (string, error) {
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
		return "", errors.New(fmt.Sprintf("CommentOutLine: %v is not supported.", lang))
	}

	header, err := commentOut(s.Language, headerComment)
	if err != nil {
		return "", err
	}

	header = strings.Trim(header, " ")

	return header, nil
}
