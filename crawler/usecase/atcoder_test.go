package usecase_test

import (
	"context"
	"errors"
	"testing"

	model "github.com/matumoto1234/cp-crawler/domain/model"
	"github.com/matumoto1234/cp-crawler/usecase"
)

type mockCrawler struct {
	fakeDo func(ctx context.Context, pageSize, pageNumber int) (*model.Page[*model.Submission], error)
}

func (m mockCrawler) Do(ctx context.Context, pageSize, pageNumber int) (*model.Page[*model.Submission], error) {
	return m.fakeDo(ctx, pageSize, pageNumber)
}

type mockSubmissionRepository struct {
	fakeSave func(ctx context.Context, submission *model.Submission) error
}

func (m mockSubmissionRepository) Save(ctx context.Context, submission *model.Submission) error {
	return m.fakeSave(ctx, submission)
}

func Test_AtcoderUseCase_CrawlAndSave(t *testing.T) {
	t.Parallel()

	tests := []struct {
		name    string
		c       *mockCrawler
		sr      *mockSubmissionRepository
		wantErr bool
	}{
		{
			name: "正常な動作",
			c: &mockCrawler{
				fakeDo: func(ctx context.Context, pageSize, pageNumber int) (*model.Page[*model.Submission], error) {
					return model.NewPage(
						[]*model.Submission{
							{
								SubmissionID: "submissionID",
								ProblemID:    "problemID",
								Language:     "language",
								SourceCode:   "source code",
							},
						},
						model.NewPaging(1, 1),
					), nil
				},
			},
			sr: &mockSubmissionRepository{
				fakeSave: func(ctx context.Context, submission *model.Submission) error {
					return nil
				},
			},
			wantErr: false,
		},
		{
			name: "Crawlerによるエラーが発生する",
			c: &mockCrawler{
				fakeDo: func(ctx context.Context, pageSize, pageNumber int) (*model.Page[*model.Submission], error) {
					return nil, errors.New("crawler error")
				},
			},
			sr: &mockSubmissionRepository{
				fakeSave: func(ctx context.Context, submission *model.Submission) error {
					return nil
				},
			},
			wantErr: true,
		},
		{
			name: "SubmissionRepositoryによるエラーが発生する",
			c: &mockCrawler{
				fakeDo: func(ctx context.Context, pageSize, pageNumber int) (*model.Page[*model.Submission], error) {
					return model.NewPage(
						[]*model.Submission{
							{
								SubmissionID: "submissionID",
								ProblemID:    "problemID",
								Language:     "language",
								SourceCode:   "source code",
							},
						},
						model.NewPaging(1, 1),
					), nil
				},
			},
			sr: &mockSubmissionRepository{
				fakeSave: func(ctx context.Context, submission *model.Submission) error {
					return errors.New("submission repository error")
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
