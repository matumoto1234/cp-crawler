package mock

import (
	"context"

	"github.com/matumoto1234/cp-crawler/domain/model"
)

type MockSubmissionRepository struct {
	FakeSave func(ctx context.Context, submission *model.Submission) error
	FakeSaveAll func(ctx context.Context, submissionList []*model.Submission) error
}

func (m MockSubmissionRepository) Save(ctx context.Context, submission *model.Submission) error {
	return m.FakeSave(ctx, submission)
}

func (m MockSubmissionRepository) SaveAll(ctx context.Context, submissionList []*model.Submission) error {
	return m.FakeSaveAll(ctx, submissionList)
}
