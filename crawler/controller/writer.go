package controller

import (
	"github.com/matumoto1234/cp-crawler/model"
	"github.com/matumoto1234/cp-crawler/service"
)

type Writer interface {
	Write(*model.Submission) error
}

type writerImpl struct {
	w service.Writer
	f service.Filer
}

func (sw *writerImpl) Write(s *model.Submission) error {
	site := s.SiteIdentifier
	sub := s.SubmissionIdentifier
	if !sw.w.IsWrittenSite(site) {
		sw.w.AppendExistingFile(site)
	}
	if sw.w.IsWrittenSub(site, sub) {
		// TODO: ここをエラーとするかどうかは要検討
		return nil
	}

	filePath, err := sw.f.MakeFilePath(s)
	if err != nil {
		return err
	}

	content, err := sw.f.MakeContent(s)
	if err != nil {
		return err
	}

	if err = sw.w.Write(site, sub, filePath, content, s.SubmittedAt); err != nil {
		return err
	}

	return nil
}

func NewWriter() Writer {
	return &writerImpl{
		w: service.NewWriter(),
		f: service.Newfiler(),
	}
}
