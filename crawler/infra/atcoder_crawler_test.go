package infra_test

import (
	"context"
	"net/http"
	"net/url"
	"testing"

	model "github.com/matumoto1234/cp-crawler/domain/model"
	repository "github.com/matumoto1234/cp-crawler/domain/repository"
	"github.com/matumoto1234/cp-crawler/infra"
	"gopkg.in/dnaeon/go-vcr.v3/recorder"
)

type mockScraper struct {
	fakeSourceCode func(ctx context.Context, submissionURL *url.URL) (string, error)
}

func (m mockScraper) SourceCode(ctx context.Context, submissionURL *url.URL) (string, error) {
	return m.fakeSourceCode(ctx, submissionURL)
}

func Test_AtcoderCrawler_Do(t *testing.T) {
	t.Parallel()

	r, _ := recorder.New("cassette/crawl")
	defer r.Stop()

	client := &http.Client{
		Transport: r,
	}

	tests := []struct {
		name       string
		pageSize   int
		pageNumber int
		s          *mockScraper
		want       *model.Page[*model.Submission]
		wantErr    bool
	}{}

	for _, tt := range tests {
		c := repository.Crawler(
			infra.NewAtcoderCrawler(client, tt.s),
		)

		got, err := c.Do(context.Background(), tt.pageSize, tt.pageNumber)
		if tt.wantErr && err == nil {
			t.Fatal("want error, but got nil")
		}
		if err != nil {
			t.Fatalf("%+v", err)
		}
		if tt.want != got {
			t.Fatalf("want %v, but got %v", tt.want, got)
		}
	}
}
