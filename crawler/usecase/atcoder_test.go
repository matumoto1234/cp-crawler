package usecase_test

import (
	"context"
	"errors"
	"testing"

	model "github.com/matumoto1234/cp-crawler/domain/model"
	"github.com/matumoto1234/cp-crawler/usecase"
	"github.com/matumoto1234/cp-crawler/usecase/mock"
)

func Test_AtcoderUseCase_CrawlAndSave(t *testing.T) {
	t.Parallel()

	tests := []struct {
		name    string
		c       *mock.MockCrawler
		sr      *mock.MockSubmissionRepository
		wantErr bool
	}{
		{
			name: "正常な動作",
			c: &mock.MockCrawler{
				FakeDo: func(ctx context.Context, pageSize, pageNumber int) (*model.Page[*model.Submission], error) {
					return model.NewPage(
						[]*model.Submission{
							{
								SubmissionID: "submissionID",
								ProblemID:    "problemID",
								Language:     "language",
							},
						},
						model.NewPaging(1, 1),
					), nil
				},
			},
			sr: &mock.MockSubmissionRepository{
				FakeSave: func(ctx context.Context, submission *model.Submission) error {
					return nil
				},
				FakeSaveAll: func(ctx context.Context, submissionList []*model.Submission) error {
					return nil
				},
			},
			wantErr: false,
		},
		{
			name: "Crawler.Do()によるエラーが発生する",
			c: &mock.MockCrawler{
				FakeDo: func(ctx context.Context, pageSize, pageNumber int) (*model.Page[*model.Submission], error) {
					return nil, errors.New("crawler error")
				},
			},
			sr: &mock.MockSubmissionRepository{
				FakeSave: func(ctx context.Context, submission *model.Submission) error {
					return nil
				},
				FakeSaveAll: func(ctx context.Context, submissionList []*model.Submission) error {
					return nil
				},
			},
			wantErr: true,
		},
		{
			name: "SubmissionRepository.SaveAll()によるエラーが発生する",
			c: &mock.MockCrawler{
				FakeDo: func(ctx context.Context, pageSize, pageNumber int) (*model.Page[*model.Submission], error) {
					return model.NewPage(
						[]*model.Submission{
							{
								SubmissionID: "submissionID",
								ProblemID:    "problemID",
								Language:     "language",
							},
						},
						model.NewPaging(1, 1),
					), nil
				},
			},
			sr: &mock.MockSubmissionRepository{
				FakeSave: func(ctx context.Context, submission *model.Submission) error {
					return nil
				},
				FakeSaveAll: func(ctx context.Context, submissionList []*model.Submission) error {
					return errors.New("something happened")
				},
			},
			wantErr: true,
		},
	}

	for _, test := range tests {
		test := test
		t.Run(test.name, func(t *testing.T) {
			t.Parallel()

			a := usecase.NewAtcoderUseCase(test.c, test.sr)

			if err := a.CrawlAndSave(context.Background()); (err != nil) != test.wantErr {
				t.Errorf("AtcoderUseCase.CrawlAndSave() error = %v, wantErr %v", err, test.wantErr)
			}
		})
	}
}
