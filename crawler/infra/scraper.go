package infra

import (
	"context"
	"net/url"

	"github.com/gocolly/colly"
	"github.com/pkg/errors"
)

type Scraper interface {
	SourceCode(ctx context.Context, submissionURL *url.URL) (string, error)
}

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

func NewScraper(collector *colly.Collector) Scraper {
	return &scraperImpl{
		collector: collector,
	}
}
