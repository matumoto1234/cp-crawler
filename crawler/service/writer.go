package service

import (
	"os"
	"path"
	"path/filepath"
	"strings"
	"time"

	"github.com/matumoto1234/cp-crawler/repository"
	"github.com/pkg/errors"
)

type Writer interface {
	Write(site, sub, filePath string, content []byte, dateTime time.Time) error
	IsWrittenSite(site string) bool
	IsWrittenSub(site, submission string) bool
	AppendExistingFile(site string) error
}

type writerImpl struct {
	// written submissions group by sites
	// e.g. written["atcoder"]["314156"]
	written map[string]map[string]bool
}

func (w *writerImpl) Write(site, sub, filePath string, content []byte, dateTime time.Time) error {
	// TODO: IsWrittenSite, IsWrittenSubエラーを書く
	w.written[site][sub] = true
	return repository.AppendSubmission(filePath, content, dateTime)
}

func (w *writerImpl) IsWrittenSite(site string) bool {
	_, ok := w.written[site]
	return ok
}

func (w *writerImpl) IsWrittenSub(site, submission string) bool {
	_, ok := w.written[site]
	if !ok {
		return false
	}
	v, ok := w.written[site][submission]
	return v && ok
}

func (w *writerImpl) AppendExistingFile(site string) error {
	if !repository.Exists("../" + site) {
		return errors.New("AppendExistingFile: Does not exist directory")
	}

	if !w.IsWrittenSite(site) {
		w.written[site] = make(map[string]bool)
	}

	err := filepath.Walk("../"+site+"/", func(filePath string, info os.FileInfo, err error) error {
		if err != nil {
			return errors.WithStack(err)
		}
		if info.IsDir() {
			return nil
		}
		fileName := path.Base(filePath)
		sub := strings.Split(fileName, ".")[0] // remove extension
		w.written[site][sub] = true
		return nil
	})
	if err != nil {
		return err
	}
	return nil
}

func NewWriter() Writer {
	return &writerImpl{
		written: make(map[string]map[string]bool),
	}
}
