package repository

import (
	"context"

	model "github.com/matumoto1234/cp-crawler/domain/model"
)

type Crawler interface {
	Page(ctx context.Context, pageSize, pageNumber uint) (*model.Page[*model.Submission], error)
}
