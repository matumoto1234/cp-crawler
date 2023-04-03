package infra_test

import (
	"context"
	"errors"
	"net/http"
	"net/url"
	"testing"

	model "github.com/matumoto1234/cp-crawler/domain/model"
	repository "github.com/matumoto1234/cp-crawler/domain/repository"
	"github.com/matumoto1234/cp-crawler/infra"
	"github.com/sebdah/goldie/v2"
	"gopkg.in/dnaeon/go-vcr.v3/recorder"
)

type mockScraper struct {
	fakeSourceCode func(ctx context.Context, submissionURL *url.URL) (string, error)
}

func (m mockScraper) SourceCode(ctx context.Context, submissionURL *url.URL) (string, error) {
	return m.fakeSourceCode(ctx, submissionURL)
}

func Test_AtcoderCrawler_Do(t *testing.T) {
	r, _ := recorder.New(".cassette/crawl")
	defer r.Stop()

	client := &http.Client{
		Transport: r,
	}

	const INF = 1 << 60

	tests := []struct {
		name       string
		pageSize   int
		pageNumber int
		s          *mockScraper
		wantErr    bool
	}{
		{
			name:       "正常な動作",
			pageSize:   50,
			pageNumber: 0,
			s: &mockScraper{
				fakeSourceCode: func(ctx context.Context, submissionURL *url.URL) (string, error) {
					return "source code", nil
				},
			},
			wantErr: false,
		},
		{
			name:       "Scraperによるエラーが発生する",
			pageSize:   50,
			pageNumber: 0,
			s: &mockScraper{
				fakeSourceCode: func(ctx context.Context, submissionURL *url.URL) (string, error) {
					return "", errors.New("error something")
				},
			},
			wantErr: true,
		},
		{
			name:       "大きな値のpageNumberによるエラーが発生する",
			pageSize:   50,
			pageNumber: INF,
			wantErr:    true,
		},
		{
			name:       "負の値のpageNumberによるエラーが発生する",
			pageSize:   50,
			pageNumber: -1,
			wantErr:    true,
		},
		{
			name:       "不適切なpageSizeによるエラーが発生する",
			pageSize:   0,
			pageNumber: 0,
			wantErr:    true,
		},
	}

	g := goldie.New(t)

	for _, test := range tests {
		test := test

		t.Run(test.name, func(t *testing.T) {
			t.Parallel()

			c := repository.Crawler(
				infra.NewAtcoderCrawler(client, test.s),
			)

			got, err := c.Do(context.Background(), test.pageSize, test.pageNumber)

			if (err != nil) != test.wantErr {
				t.Fatalf("AtcoderCrawler.Do() error = %+v, wantErr %v", err, test.wantErr)
			}

			g.AssertJson(t, test.name, got)
		})
	}
}

func convertToByteSlice(*model.Page[*model.Submission]) []byte {
	return nil
}
