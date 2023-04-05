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
func (f *fileSystemImpl) Dir(siteID model.Site, problemID, contestID string) (string, error) {
	// crawlerの親に作りたいので../を先頭に追加
	return filepath.Join("../", siteID.String(), contestID, problemID), nil
}

// WriteFile() : ファイルを書き込む
func (f *fileSystemImpl) WriteFile(dir, fileName string, content []byte) error {
	if err := os.MkdirAll(dir, 0755); err != nil {
		return errors.WithStack(err)
	}

	path := filepath.Join(dir, fileName)

	if err := os.WriteFile(path, content, 0755); err != nil {
		return errors.WithStack(err)
	}

	return nil
}

// toExtension() : 言語名を元に拡張子を返す
func toExtension(lang string) (string, error) {
	// mapにすると順序が入れ替わるのでsliceで管理
	// バージョンの問題からcontainsで比較する関係上
	// 「C++はCより先に比較しなければならない」といった制約がある
	extensionList := []struct {
		lang string
		ext  string
	}{
		{lang: "Awk", ext: "awk"},
		{lang: "C#", ext: "cs"},
		{lang: "C++", ext: "cpp"},
		{lang: "Bash", ext: "sh"},
		{lang: "Brainfuck", ext: "bf"},
		{lang: "COBOL", ext: "cobol"},
		{lang: "Clojure", ext: "clj"},
		{lang: "Lisp", ext: "lisp"},
		{lang: "Crystal", ext: "cr"},
		{lang: "Fortran", ext: "f"},
		{lang: "Go", ext: "go"},
		{lang: "Haskell", ext: "hs"},
		{lang: "JavaScript", ext: "js"},
		{lang: "Java", ext: "java"},
		{lang: "Julia", ext: "jl"},
		{lang: "Kotlin", ext: "kt"},
		{lang: "MoonScript", ext: "moon"},
		{lang: "Nim", ext: "nim"},
		{lang: "OCaml", ext: "ml"},
		{lang: "Objective", ext: "m"},
		{lang: "Octave", ext: "m"},
		{lang: "PHP", ext: "php"},
		{lang: "Pascal", ext: "pas"},
		{lang: "Perl", ext: "pl"},
		{lang: "Py", ext: "py"},
		{lang: "Ruby", ext: "rb"},
		{lang: "Rust", ext: "rs"},
		{lang: "Scala", ext: "scala"},
		{lang: "Scheme", ext: "ss"},
		{lang: "Sed", ext: "sed"},
		{lang: "Swift", ext: "swift"},
		{lang: "Text", ext: "txt"},
		{lang: "TypeScript", ext: "ts"},
		{lang: "Unlambda", ext: "unl"},
		{lang: "Basic", ext: "vb"},
		{lang: "ML", ext: "sml"},
		{lang: "F#", ext: "fs"},
		{lang: "C", ext: "c"},
		{lang: "D", ext: "d"},
	}

	for _, v := range extensionList {
		if strings.Contains(lang, v.lang) {
			return v.ext, nil
		}
	}
	return "", errors.New(fmt.Sprintf("%s is not supported.", lang))
}
