package atcoder

import (
	"context"
	"log"
	"net/url"
	"os"

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

	s.collector.Wait()

	logInfo := log.New(os.Stdout, "[INFO] ", log.LstdFlags)
	logInfo.Println("scraped : ", submissionURL.String())

	return sourceCode, nil
}

func NewScraper(collector *colly.Collector) service.Scraper {
	return &scraperImpl{
		collector: collector,
	}
}
