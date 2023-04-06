package service

import (
	"context"

	"github.com/matumoto1234/cp-crawler/domain/model"
)

type RepositoryManager interface {
	Exists(ctx context.Context, s *model.Submission) (bool, error)
}
