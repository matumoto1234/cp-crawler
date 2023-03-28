package usecase

import (
	"context"

	repository "github.com/matumoto1234/cp-crawler/domain/repository"
)

type AtcoderUseCase interface {
	CrawlAndSave(ctx context.Context) *Error
}

type atcoderUseCaseImpl struct {
	c  repository.Crawler
	sr repository.SubmissionRepository
}

func (a atcoderUseCaseImpl) CrawlAndSave(ctx context.Context) *Error {
	// AtCoderに提出できるソースコード長が最大で512Kib
	// 512 * 1024 * pageSizeがメモリにのっても大丈夫なpageSizeを指定する
	page, err := a.c.Do(ctx, 50, 0)
	if err != nil {
		return NewError(err, ErrCrawlerError)
	}

	for _, submission := range page.ItemList {
		if err := a.sr.Save(ctx, submission); err != nil {
			return NewError(err, ErrRepositoryError)
		}
	}
	return nil
}

func NewAtcoderUseCase(crawler repository.Crawler, submissionRepo repository.SubmissionRepository) *atcoderUseCaseImpl {
	return &atcoderUseCaseImpl{
		c:  crawler,
		sr: submissionRepo,
	}
}
