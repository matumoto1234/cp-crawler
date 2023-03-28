package domain

import (
	"context"

	model "github.com/matumoto1234/cp-crawler/domain/model"
)

type SubmissionRepository interface {
	Save(ctx context.Context, s *model.Submission) error
}
