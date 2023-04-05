package repository

import (
	"context"

	model "github.com/matumoto1234/cp-crawler/domain/model"
)

type SubmissionRepository interface {
	Save(ctx context.Context, s *model.Submission) error
	SaveAll(ctx context.Context, submissionList []*model.Submission) error
}
