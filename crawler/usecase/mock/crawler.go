package mock

import (
	"context"

	"github.com/matumoto1234/cp-crawler/domain/model"
	"github.com/matumoto1234/cp-crawler/domain/repository"
)

var _ repository.Crawler = (*MockCrawler)(nil)

type MockCrawler struct {
	FakePage func(ctx context.Context, pageSize, pageNumber uint) (*model.Page[*model.Submission], error)
}

func (m MockCrawler) Page(ctx context.Context, pageSize, pageNumber uint) (*model.Page[*model.Submission], error) {
	return m.FakePage(ctx, pageSize, pageNumber)
}
