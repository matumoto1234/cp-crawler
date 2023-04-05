package atcoder

import (
	"context"
	"net/url"

	"github.com/gocolly/colly"
	"github.com/matumoto1234/cp-crawler/domain/service"
	"github.com/pkg/errors"
)

type scraperImpl struct {
	collector *colly.Collector
}

func (s scraperImpl) SourceCode(ctx context.Context, submissionURL *url.URL) (string, error) {
	var sourceCode string
	s.collector.OnHTML("body", func(e *colly.HTMLElement) {
		sourceCode = e.DOM.Find("#submission-code").Text()
	})

	if err := s.collector.Visit(submissionURL.String()); err != nil {
		return "", errors.WithStack(err)
	}

	return sourceCode, nil
}

func NewScraper(collector *colly.Collector) service.Scraper {
	return &scraperImpl{
		collector: collector,
	}
}
