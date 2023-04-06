package mock

import (
	"context"

	"github.com/matumoto1234/cp-crawler/domain/model"
)

type MockCrawler struct {
	FakeDo func(ctx context.Context, pageSize, pageNumber int) (*model.Page[*model.Submission], error)
}

func (m MockCrawler) Do(ctx context.Context, pageSize, pageNumber int) (*model.Page[*model.Submission], error) {
	return m.FakeDo(ctx, pageSize, pageNumber)
}
