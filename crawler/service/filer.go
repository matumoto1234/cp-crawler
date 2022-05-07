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

type comment struct {
	lang string
	affixes [2]string
}

func newComment(lang string, affixes [2]string) comment {
	return comment{
		lang: lang,
		affixes: affixes,
	}
}

type extension struct {
	lang string
	ext string
}

func newExtension(lang string, ext string) extension {
	return extension{
		lang: lang,
		ext: ext,
	}
}

type filerImpl struct {
	comments   []comment
	extensions []extension
}

func (c *filerImpl) commentOutLine(lang, line string) (string, error) {
	for _, v := range c.comments {
		contains := strings.Contains(lang, v.lang)
		if contains {

			prefix := v.affixes[0]
			suffix := v.affixes[1]
			return prefix + line + suffix, nil
		}
	}
	return "", errors.New(fmt.Sprintf("CommentOutLine: %v is not supported.", lang))
}

func (c *filerImpl) toExtension(lang string) (string, error) {
	for _, v := range c.extensions {
		contains := strings.Contains(lang, v.lang)
		if contains {
			return v.ext, nil
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
	comments := []comment{
		newComment("Awk", [2]string{"#", ""}),
		newComment("C#", [2]string{"//", ""}),
		newComment("C++", [2]string{"//", ""}),
		newComment("Bash", [2]string{"#", ""}),
		newComment("Brainfuck", [2]string{"#", ""}),
		newComment("COBOL", [2]string{"*", ""}),
		newComment("Clojure", [2]string{";", ""}),
		newComment("Lisp", [2]string{";", ""}),
		newComment("Crystal", [2]string{"#", ""}),
		newComment("Fortran", [2]string{"*", ""}),
		newComment("Go", [2]string{"//", ""}),
		newComment("Haskell", [2]string{"--", ""}),
		newComment("JavaScript", [2]string{"//", ""}),
		newComment("Java", [2]string{"//", ""}),
		newComment("Julia", [2]string{"#", ""}),
		newComment("Kotlin", [2]string{"//", ""}),
		newComment("MoonScript", [2]string{"--", ""}),
		newComment("Nim", [2]string{"#", ""}),
		newComment("OCaml", [2]string{"*", "*"}),
		newComment("Objective", [2]string{"//", ""}),
		newComment("Octave", [2]string{"%{", "%}"}),
		newComment("PHP", [2]string{"<!--", "--?"}),
		newComment("Pascal", [2]string{"//", ""}),
		newComment("Perl", [2]string{"#", ""}),
		newComment("Py", [2]string{"#", ""}),
		newComment("Ruby", [2]string{"#", ""}),
		newComment("Rust", [2]string{"//", ""}),
		newComment("Scala", [2]string{"//", ""}),
		newComment("Scheme", [2]string{";", ""}),
		newComment("Sed", [2]string{"//", ""}), // inaccurate
		newComment("Swift", [2]string{"//", ""}),
		newComment("Text", [2]string{"//", ""}), // inaccurate
		newComment("TypeScript", [2]string{"//", ""}),
		newComment("Unlambda", [2]string{"#", ""}),
		newComment("Basic", [2]string{"'", ""}),
		newComment("ML", [2]string{"*", "*"}),
		newComment("F#", [2]string{"//", ""}),
		newComment("C", [2]string{"//", ""}),
		newComment("D", [2]string{"//", ""}),
	}

	extensions := []extension{
		newExtension("Awk", "awk"),
		newExtension("C#", "cs"),
		newExtension("C++", "cpp"),
		newExtension("Bash", "sh"),
		newExtension("Brainfuck", "bf"),
		newExtension("COBOL", "cobol"),
		newExtension("Clojure", "clj"),
		newExtension("Lisp", "lisp"),
		newExtension("Crystal", "cr"),
		newExtension("Fortran", "f"),
		newExtension("Go", "go"),
		newExtension("Haskell", "hs"),
		newExtension("JavaScript", "js"),
		newExtension("Java", "java"),
		newExtension("Julia", "jl"),
		newExtension("Kotlin", "kt"),
		newExtension("MoonScript", "moon"),
		newExtension("Nim", "nim"),
		newExtension("OCaml", "ml"),
		newExtension("Objective", "m"),
		newExtension("Octave", "m"),
		newExtension("PHP", "php"),
		newExtension("Pascal", "pas"),
		newExtension("Perl", "pl"),
		newExtension("Py", "py"),
		newExtension("Ruby", "rb"),
		newExtension("Rust", "rs"),
		newExtension("Scala", "scala"),
		newExtension("Scheme", "ss"),
		newExtension("Sed", "sed"),
		newExtension("Swift", "swift"),
		newExtension("Text", "txt"),
		newExtension("TypeScript", "ts"),
		newExtension("Unlambda", "unl"),
		newExtension("Basic", "vb"),
		newExtension("ML", "sml"),
		newExtension("F#", "fs"),
		newExtension("C", "c"),
		newExtension("D", "d"),
	}

	return &filerImpl{
		comments:   comments,
		extensions: extensions,
	}
}
