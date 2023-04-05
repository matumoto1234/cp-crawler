package infra_test

import (
	"context"
	"log"
	"net/http"
	"os"
	"testing"
	"time"

	repository "github.com/matumoto1234/cp-crawler/domain/repository"
	"github.com/matumoto1234/cp-crawler/infra"
	"github.com/sebdah/goldie/v2"
	"golang.org/x/time/rate"
	"gopkg.in/dnaeon/go-vcr.v3/recorder"
)

func Test_AtcoderCrawler_Do(t *testing.T) {
	if testing.Short() {
		t.SkipNow()
	}

	t.Parallel()

	r, err := recorder.New(".cassette/crawl")
	if err != nil {
		t.Fatal(err)
	}

	defer r.Stop()

	logInfo := log.New(os.Stdout, "[INFO] ", log.Ldate|log.Ltime|log.Lshortfile)

	r.SetRealTransport(infra.NewRateLimitTransport(
		infra.NewLoggingTransport(
			http.DefaultTransport,
			logInfo,
		),
		rate.NewLimiter(rate.Every(2*time.Second), 1), // 2秒に1回
	))

	client := &http.Client{
		Transport: r,
	}

	const INF = 1 << 30

	tests := []struct {
		name       string
		pageSize   int
		pageNumber int
		wantErr    bool
	}{
		{
			name:       "正常な動作",
			pageSize:   50,
			pageNumber: 2,
			wantErr:    false,
		},
		{
			name:       "正常な動作2",
			pageSize:   50,
			pageNumber: 0,
			wantErr:    false,
		},
		{
			name:       "大きな値のpageNumberを指定してもエラーは発生しない",
			pageSize:   50,
			pageNumber: INF,
			wantErr:    false,
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

	for _, test := range tests {
		test := test

		t.Run(test.name, func(t *testing.T) {
			// t.Parallel()をつけた場合、go-vcrがカセットを更新しようとした場合、
			// ロックがかかってしまってファイルが正常に更新されないのでt.Parallel()はつけない

			g := goldie.New(t)

			c := repository.Crawler(
				infra.NewAtcoderCrawler(client),
			)

			got, err := c.Do(context.Background(), test.pageSize, test.pageNumber)

			if (err != nil) != test.wantErr {
				t.Fatalf("AtcoderCrawler.Do() error = %+v, wantErr %v", err, test.wantErr)
			}

			g.AssertJson(t, test.name, got)
		})
	}
}
