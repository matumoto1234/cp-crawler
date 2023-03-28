package domain

import (
	"context"

	model "github.com/matumoto1234/cp-crawler/domain/model"
)

type Crawler interface {
	Do(ctx context.Context, pageSize, pageNumber int) (*model.Page[*model.Submission], error)
}
