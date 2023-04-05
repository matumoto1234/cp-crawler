package infra_test

import (
	"context"
	"net/url"
	"testing"
	"time"

	"github.com/gocolly/colly"
	"github.com/gocolly/colly/debug"
	"github.com/matumoto1234/cp-crawler/infra"
)

func Test_Scraper_SourceCode(t *testing.T) {
	if testing.Short() {
		t.SkipNow()
	}

	t.Parallel()

	c := colly.NewCollector(
		colly.Debugger(&debug.LogDebugger{}),
	)

	c.Limit(&colly.LimitRule{
		Parallelism: 2,
		RandomDelay: 5 * time.Second,
	})

	u, _ := url.Parse("https://atcoder.jp/contests/abc117/submissions/4156454")

	s := infra.NewScraper(c)
	code, err := s.SourceCode(context.Background(), u)
	if err != nil {
		t.Fatal(err)
	}

	t.Log(code)
}
