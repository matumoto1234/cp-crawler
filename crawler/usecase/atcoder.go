package usecase

import (
	"context"

	repository "github.com/matumoto1234/cp-crawler/domain/repository"
)

type AtcoderUseCase interface {
	CrawlAndSave(ctx context.Context) error
}

type atcoderUseCaseImpl struct {
	c  repository.Crawler
	sr repository.SubmissionRepository
}

func (a atcoderUseCaseImpl) CrawlAndSave(ctx context.Context) error {
	ceilDiv := func(a, b int) int {
		return (a + b - 1) / b
	}

	var pageNumber int
	for {
		// AtCoderに提出できるソースコード長が最大で512Kib
		// 512 * 1024 * pageSizeがメモリにのっても大丈夫なpageSizeを指定する
		const pageSize = 50

		page, err := a.c.Do(ctx, pageSize, pageNumber)
		if err != nil {
			return err
		}

		// pageNumber == ceilDiv(page.Paging.TotalCount, 50)のときは最後のページ
		if pageNumber == ceilDiv(page.Paging.TotalCount, pageSize) {
			break
		}

		pageNumber++

		if err := a.sr.SaveAll(ctx, page.ItemList); err != nil {
			return err
		}
	}

	return nil
}

func NewAtcoderUseCase(crawler repository.Crawler, submissionRepo repository.SubmissionRepository) AtcoderUseCase {
	return &atcoderUseCaseImpl{
		c:  crawler,
		sr: submissionRepo,
	}
}
