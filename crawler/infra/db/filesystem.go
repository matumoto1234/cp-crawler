package db

import (
	"fmt"
	"os"
	"path/filepath"
	"strings"

	model "github.com/matumoto1234/cp-crawler/domain/model"
	"github.com/pkg/errors"
)

type fileSystemImpl struct {
}

func NewFileSystem() *fileSystemImpl {
	return &fileSystemImpl{}
}

// FileName() : ファイル名を返す
func (f *fileSystemImpl) FileName(lang, submissionID string) (string, error) {
	ext, err := toExtension(lang)
	if err != nil {
		return "", err
	}

	return fmt.Sprintf("%v.%v", submissionID, ext), nil
}

// Dir() : 保存先ファイルパスを返す
func (f *fileSystemImpl) Dir(siteID model.Site, problemID string) (string, error) {
	dir := filepath.Join(siteID.String(), problemID)

	// crawlerの親に作りたいので../を先頭に追加
	return filepath.Join("../", dir), nil
}

// WriteFile() : ファイルを書き込む
func (f *fileSystemImpl) WriteFile(dir, fileName string, content []byte) error {
	if err := os.MkdirAll(dir, 755); err != nil {
		return errors.WithStack(err)
	}

	path := filepath.Join(dir, fileName)

	if err := os.WriteFile(path, content, 755); err != nil {
		return errors.WithStack(err)
	}

	return nil
}

// toExtension() : 言語名を元に拡張子を返す
func toExtension(lang string) (string, error) {
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
	return "", errors.New(fmt.Sprintf("%s is not supported.", lang))
}
