package infra_test

import (
	"context"
	"net/url"
	"testing"
	"time"

	"github.com/matumoto1234/cp-crawler/domain/model"
	"github.com/matumoto1234/cp-crawler/domain/model/judge"
	"github.com/matumoto1234/cp-crawler/infra"
	"github.com/matumoto1234/cp-crawler/infra/mock"
	"github.com/pkg/errors"
)

func Test_SubmissionRepository_Save(t *testing.T) {
	t.Parallel()

	u, _ := url.Parse("https://example.com/submission/url")

	tests := []struct {
		name    string
		f       *mock.MockFileSystem
		g       *mock.MockGit
		s       *mock.MockScraper
		m       *mock.MockRepositoryManager
		sub     *model.Submission
		wantErr bool
	}{
		{
			name: "正常な処理",
			f: &mock.MockFileSystem{
				FakeFileName: func(lang, submissionID string) (string, error) {
					return "", nil
				},
				FakeDir: func(siteID model.Site, problemID, contestID string) (string, error) {
					return "", nil
				},
				FakeWriteFile: func(dir, fileName string, content []byte) error {
					return nil
				},
			},
			g: &mock.MockGit{
				FakeAdd: func(path string) error {
					return nil
				},
				FakeCommit: func(commitMsg string, dateTime time.Time) error {
					return nil
				},
				FakePush: func() error {
					return nil
				},
			},
			s: &mock.MockScraper{
				FakeSourceCode: func(ctx context.Context, url *url.URL) (string, error) {
					return "", nil
				},
			},
			m: &mock.MockRepositoryManager{
				FakeExists: func(ctx context.Context, s *model.Submission) (bool, error) {
					return false, nil
				},
			},
			sub: &model.Submission{
				SiteID:        model.SiteAtcoder,
				ProblemID:     "problem",
				SubmissionID:  "submission",
				Status:        judge.Accepted,
				Language:      "C++",
				SubmittedAt:   time.Now(),
				SubmissionURL: u,
			},
			wantErr: false,
		},
		{
			name: "FileName()でエラー",
			f: &mock.MockFileSystem{
				FakeFileName: func(lang, submissionID string) (string, error) {
					return "", errors.New("something happened")
				},
				FakeDir: func(siteID model.Site, problemID, contestID string) (string, error) {
					return "", nil
				},
				FakeWriteFile: func(dir, fileName string, content []byte) error {
					return nil
				},
			},
			g: &mock.MockGit{
				FakeAdd: func(path string) error {
					return nil
				},
				FakeCommit: func(commitMsg string, dateTime time.Time) error {
					return nil
				},
				FakePush: func() error {
					return nil
				},
			},
			s: &mock.MockScraper{
				FakeSourceCode: func(ctx context.Context, url *url.URL) (string, error) {
					return "", nil
				},
			},
			m: &mock.MockRepositoryManager{
				FakeExists: func(ctx context.Context, s *model.Submission) (bool, error) {
					return false, nil
				},
			},
			sub: &model.Submission{
				SiteID:        model.SiteAtcoder,
				ProblemID:     "problem",
				SubmissionID:  "submission",
				Status:        judge.Accepted,
				Language:      "C++",
				SubmittedAt:   time.Now(),
				SubmissionURL: u,
			},
			wantErr: true,
		},
		{
			name: "Dir()でエラー",
			f: &mock.MockFileSystem{
				FakeFileName: func(lang, submissionID string) (string, error) {
					return "", nil
				},
				FakeDir: func(siteID model.Site, problemID, contestID string) (string, error) {
					return "", errors.New("something happened")
				},
				FakeWriteFile: func(dir, fileName string, content []byte) error {
					return nil
				},
			},
			g: &mock.MockGit{
				FakeAdd: func(path string) error {
					return nil
				},
				FakeCommit: func(commitMsg string, dateTime time.Time) error {
					return nil
				},
				FakePush: func() error {
					return nil
				},
			},
			s: &mock.MockScraper{
				FakeSourceCode: func(ctx context.Context, url *url.URL) (string, error) {
					return "", nil
				},
			},
			m: &mock.MockRepositoryManager{
				FakeExists: func(ctx context.Context, s *model.Submission) (bool, error) {
					return false, nil
				},
			},
			sub: &model.Submission{
				SiteID:        model.SiteAtcoder,
				ProblemID:     "problem",
				SubmissionID:  "submission",
				Status:        judge.Accepted,
				Language:      "C++",
				SubmittedAt:   time.Now(),
				SubmissionURL: u,
			},
			wantErr: true,
		},
		{
			name: "WriteFile()でエラー",
			f: &mock.MockFileSystem{
				FakeFileName: func(lang, submissionID string) (string, error) {
					return "", nil
				},
				FakeDir: func(siteID model.Site, problemID, contestID string) (string, error) {
					return "", nil
				},
				FakeWriteFile: func(dir, fileName string, content []byte) error {
					return errors.New("something happened")
				},
			},
			g: &mock.MockGit{
				FakeAdd: func(path string) error {
					return nil
				},
				FakeCommit: func(commitMsg string, dateTime time.Time) error {
					return nil
				},
				FakePush: func() error {
					return nil
				},
			},
			s: &mock.MockScraper{
				FakeSourceCode: func(ctx context.Context, url *url.URL) (string, error) {
					return "", nil
				},
			},
			m: &mock.MockRepositoryManager{
				FakeExists: func(ctx context.Context, s *model.Submission) (bool, error) {
					return false, nil
				},
			},
			sub: &model.Submission{
				SiteID:        model.SiteAtcoder,
				ProblemID:     "problem",
				SubmissionID:  "submission",
				Status:        judge.Accepted,
				Language:      "C++",
				SubmittedAt:   time.Now(),
				SubmissionURL: u,
			},
			wantErr: true,
		},
		{
			name: "Add()でエラー",
			f: &mock.MockFileSystem{
				FakeFileName: func(lang, submissionID string) (string, error) {
					return "", nil
				},
				FakeDir: func(siteID model.Site, problemID, contestID string) (string, error) {
					return "", nil
				},
				FakeWriteFile: func(dir, fileName string, content []byte) error {
					return nil
				},
			},
			g: &mock.MockGit{
				FakeAdd: func(path string) error {
					return errors.New("something happened")
				},
				FakeCommit: func(commitMsg string, dateTime time.Time) error {
					return nil
				},
				FakePush: func() error {
					return nil
				},
			},
			s: &mock.MockScraper{
				FakeSourceCode: func(ctx context.Context, url *url.URL) (string, error) {
					return "", nil
				},
			},
			m: &mock.MockRepositoryManager{
				FakeExists: func(ctx context.Context, s *model.Submission) (bool, error) {
					return false, nil
				},
			},
			sub: &model.Submission{
				SiteID:        model.SiteAtcoder,
				ProblemID:     "problem",
				SubmissionID:  "submission",
				Status:        judge.Accepted,
				Language:      "C++",
				SubmittedAt:   time.Now(),
				SubmissionURL: u,
			},
			wantErr: true,
		},
		{
			name: "Commit()でエラー",
			f: &mock.MockFileSystem{
				FakeFileName: func(lang, submissionID string) (string, error) {
					return "", nil
				},
				FakeDir: func(siteID model.Site, problemID, contestID string) (string, error) {
					return "", nil
				},
				FakeWriteFile: func(dir, fileName string, content []byte) error {
					return nil
				},
			},
			g: &mock.MockGit{
				FakeAdd: func(path string) error {
					return nil
				},
				FakeCommit: func(commitMsg string, dateTime time.Time) error {
					return errors.New("something happened")
				},
				FakePush: func() error {
					return nil
				},
			},
			s: &mock.MockScraper{
				FakeSourceCode: func(ctx context.Context, url *url.URL) (string, error) {
					return "", nil
				},
			},
			m: &mock.MockRepositoryManager{
				FakeExists: func(ctx context.Context, s *model.Submission) (bool, error) {
					return false, nil
				},
			},
			sub: &model.Submission{
				SiteID:        model.SiteAtcoder,
				ProblemID:     "problem",
				SubmissionID:  "submission",
				Status:        judge.Accepted,
				Language:      "C++",
				SubmittedAt:   time.Now(),
				SubmissionURL: u,
			},
			wantErr: true,
		},
		{
			name: "Push()でエラー",
			f: &mock.MockFileSystem{
				FakeFileName: func(lang, submissionID string) (string, error) {
					return "", nil
				},
				FakeDir: func(siteID model.Site, problemID, contestID string) (string, error) {
					return "", nil
				},
				FakeWriteFile: func(dir, fileName string, content []byte) error {
					return nil
				},
			},
			g: &mock.MockGit{
				FakeAdd: func(path string) error {
					return nil
				},
				FakeCommit: func(commitMsg string, dateTime time.Time) error {
					return nil
				},
				FakePush: func() error {
					return errors.New("something happened")
				},
			},
			s: &mock.MockScraper{
				FakeSourceCode: func(ctx context.Context, url *url.URL) (string, error) {
					return "", nil
				},
			},
			m: &mock.MockRepositoryManager{
				FakeExists: func(ctx context.Context, s *model.Submission) (bool, error) {
					return false, nil
				},
			},
			sub: &model.Submission{
				SiteID:        model.SiteAtcoder,
				ProblemID:     "problem",
				SubmissionID:  "submission",
				Status:        judge.Accepted,
				Language:      "C++",
				SubmittedAt:   time.Now(),
				SubmissionURL: u,
			},
			wantErr: true,
		},
		{
			name: "SourceCode()でエラー",
			f: &mock.MockFileSystem{
				FakeFileName: func(lang, submissionID string) (string, error) {
					return "", nil
				},
				FakeDir: func(siteID model.Site, problemID, contestID string) (string, error) {
					return "", nil
				},
				FakeWriteFile: func(dir, fileName string, content []byte) error {
					return nil
				},
			},
			g: &mock.MockGit{
				FakeAdd: func(path string) error {
					return nil
				},
				FakeCommit: func(commitMsg string, dateTime time.Time) error {
					return nil
				},
				FakePush: func() error {
					return nil
				},
			},
			s: &mock.MockScraper{
				FakeSourceCode: func(ctx context.Context, url *url.URL) (string, error) {
					return "", errors.New("something happened")
				},
			},
			m: &mock.MockRepositoryManager{
				FakeExists: func(ctx context.Context, s *model.Submission) (bool, error) {
					return false, nil
				},
			},
			sub: &model.Submission{
				SiteID:        model.SiteAtcoder,
				ProblemID:     "problem",
				SubmissionID:  "submission",
				Status:        judge.Accepted,
				Language:      "C++",
				SubmittedAt:   time.Now(),
				SubmissionURL: u,
			},
			wantErr: true,
		},
		{
			name: "Exists()でエラー",
			f: &mock.MockFileSystem{
				FakeFileName: func(lang, submissionID string) (string, error) {
					return "", nil
				},
				FakeDir: func(siteID model.Site, problemID, contestID string) (string, error) {
					return "", nil
				},
				FakeWriteFile: func(dir, fileName string, content []byte) error {
					return nil
				},
			},
			g: &mock.MockGit{
				FakeAdd: func(path string) error {
					return nil
				},
				FakeCommit: func(commitMsg string, dateTime time.Time) error {
					return nil
				},
				FakePush: func() error {
					return nil
				},
			},
			s: &mock.MockScraper{
				FakeSourceCode: func(ctx context.Context, url *url.URL) (string, error) {
					return "", nil
				},
			},
			m: &mock.MockRepositoryManager{
				FakeExists: func(ctx context.Context, s *model.Submission) (bool, error) {
					return false, errors.New("something happened")
				},
			},
			sub: &model.Submission{
				SiteID:        model.SiteAtcoder,
				ProblemID:     "problem",
				SubmissionID:  "submission",
				Status:        judge.Accepted,
				Language:      "C++",
				SubmittedAt:   time.Now(),
				SubmissionURL: u,
			},
			wantErr: true,
		},
		{
			name: "Exists()のモックがtrueを返す",
			f: &mock.MockFileSystem{
				FakeFileName: func(lang, submissionID string) (string, error) {
					return "", nil
				},
				FakeDir: func(siteID model.Site, problemID, contestID string) (string, error) {
					return "", nil
				},
				FakeWriteFile: func(dir, fileName string, content []byte) error {
					return nil
				},
			},
			g: &mock.MockGit{
				FakeAdd: func(path string) error {
					return nil
				},
				FakeCommit: func(commitMsg string, dateTime time.Time) error {
					return nil
				},
				FakePush: func() error {
					return nil
				},
			},
			s: &mock.MockScraper{
				FakeSourceCode: func(ctx context.Context, url *url.URL) (string, error) {
					return "", nil
				},
			},
			m: &mock.MockRepositoryManager{
				FakeExists: func(ctx context.Context, s *model.Submission) (bool, error) {
					return true, nil
				},
			},
			sub: &model.Submission{
				SiteID:        model.SiteAtcoder,
				ProblemID:     "problem",
				SubmissionID:  "submission",
				Status:        judge.Accepted,
				Language:      "C++",
				SubmittedAt:   time.Now(),
				SubmissionURL: u,
			},
			wantErr: false,
		},
	}

	for _, test := range tests {
		test := test
		t.Run(test.name, func(t *testing.T) {
			t.Parallel()

			sr := infra.NewSubmissionRepository(test.g, test.f, test.s, test.m)
			if err := sr.Save(context.Background(), test.sub); (err != nil) != test.wantErr {
				t.Fatalf("Save() error = %v, wantErr %v", err, test.wantErr)
			}
		})
	}
}
