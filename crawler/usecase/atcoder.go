package usecase

import (
	"context"

	"github.com/hashicorp/go-multierror"
	repository "github.com/matumoto1234/cp-crawler/domain/repository"
)

type AtcoderUseCase interface {
	CrawlAndSave(ctx context.Context) error
}

type atcoderUseCaseImpl struct {
	c  repository.Crawler
	sr repository.SubmissionRepository
}

func NewAtcoderUseCase(crawler repository.Crawler, submissionRepo repository.SubmissionRepository) AtcoderUseCase {
	return &atcoderUseCaseImpl{
		c:  crawler,
		sr: submissionRepo,
	}
}

func (a *atcoderUseCaseImpl) CrawlAndSave(ctx context.Context) error {
	var errs error
	var pageNumber uint

	for {
		// AtCoderに提出できるソースコード長が最大で512Kib
		// 512 * 1024 * pageSizeがメモリにのっても大丈夫なpageSizeを指定する
		const pageSize = 50

		page, err := a.c.Page(ctx, pageSize, pageNumber)
		if err != nil {
			// 処理を中断ではなく、エラーを記録して続行する
			errs = multierror.Append(errs, err)
			continue
		}

		if isLastPage(pageNumber, page.Paging.TotalCount, pageSize) {
			break
		}

		pageNumber++

		if err := a.sr.SaveAll(ctx, page.ItemList); err != nil {
			// 処理を中断ではなく、エラーを記録して続行する
			errs = multierror.Append(errs, err)
			continue
		}
	}

	if errs != nil {
		return errs
	}

	return nil
}

func isLastPage(pageNumber, totalPage, pageSize uint) bool {
	return pageNumber == ceilDiv(totalPage, pageSize)
}

func ceilDiv(a, b uint) uint {
	return (a + b - 1) / b
}
