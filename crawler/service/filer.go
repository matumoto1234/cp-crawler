package service

import (
	"fmt"
	"path"
	"strings"

	"github.com/matumoto1234/cp-crawler/model"
	"github.com/pkg/errors"
)

type Filer interface {
	MakeFilePath(*model.Submission) (string, error)
	MakeContent(s *model.Submission) ([]byte, error)
	commentOutLine(lang, line string) (string, error)
	toExtension(lang string) (string, error)
}

type affixes [2]string

type filerImpl struct {
	comments   map[string]affixes
	extensions map[string]string
}

func (c *filerImpl) commentOutLine(lang, line string) (string, error) {
	for key, affix := range c.comments {
		contains := strings.Contains(lang, key)
		if contains {

			prefix := affix[0]
			suffix := affix[1]
			return prefix + line + suffix, nil
		}
	}
	return "", errors.New(fmt.Sprintf("CommentOutLine: %v is not supported.", lang))
}

func (c *filerImpl) toExtension(lang string) (string, error) {
	for key, ext := range c.extensions {
		contains := strings.Contains(lang, key)
		if contains {
			return ext, nil
		}
	}
	return "", errors.New(fmt.Sprintf("GetExtension: %v is not supported.", lang))
}

func (c *filerImpl) MakeFilePath(s *model.Submission) (string, error) {
	site := s.SiteIdentifier
	problem := s.ProblemIdentifier
	dir := path.Join(site, problem)

	submission := s.SubmissionIdentifier
	extension, err := c.toExtension(s.Language)
	if err != nil {
		return "", err
	}

	fileName := fmt.Sprintf("%v.%v", submission, extension)
	// crawlerの親に作りたいので../を先頭に追加
	filePath := path.Join("../", dir, fileName)
	return filePath, nil
}

func (c *filerImpl) MakeContent(s *model.Submission) ([]byte, error) {
	// make header
	headerStr := fmt.Sprintf(" detail: %v ", s.SubmissionURL)
	header, err := c.commentOutLine(s.Language, headerStr)
	if err != nil {
		return nil, err
	}
	header = strings.Trim(header, " ")

	code := s.SourceCode
	content := []byte(fmt.Sprintf("%v\n%v", header, code))
	return content, nil
}

func Newfiler() Filer {
	comments := map[string]affixes{
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

	extensions := map[string]string{
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

	return &filerImpl{
		comments:   comments,
		extensions: extensions,
	}
}
