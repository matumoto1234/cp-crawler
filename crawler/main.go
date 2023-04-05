package main

import (
	"log"
	"net/http"
	"os"
	"time"

	"github.com/gocolly/colly"
	"github.com/gocolly/colly/debug"
	"github.com/matumoto1234/cp-crawler/controller"
	domain "github.com/matumoto1234/cp-crawler/domain/repository"
	"github.com/matumoto1234/cp-crawler/infra"
	"github.com/matumoto1234/cp-crawler/infra/db"
	"github.com/matumoto1234/cp-crawler/usecase"
	"golang.org/x/time/rate"
)

func main() {
	logInfo := log.New(os.Stdout, "[INFO] ", log.LstdFlags)
	logError := log.New(os.Stderr, "[WARN] ", log.LstdFlags)

	logInfo.Println("cp-crawler started.")

	lt := infra.NewLoggingTransport(
		infra.NewRateLimitTransport(
			http.DefaultTransport,
			rate.NewLimiter(rate.Every(2*time.Second), 1), // 1 request every 2 seconds
		),
		logInfo,
	)

	rlt := infra.NewRateLimitTransport(
		lt,
		rate.NewLimiter(rate.Every(2*time.Second), 1), // 1 request every 2 seconds
	)

	client := &http.Client{
		Transport: rlt,
	}

	var ac domain.Crawler
	ac = infra.NewAtcoderCrawler(client)

	collector := colly.NewCollector(
		colly.Debugger(&debug.LogDebugger{}),
	)

	collector.Limit(&colly.LimitRule{
		Parallelism: 2,
		RandomDelay: 5 * time.Second,
	})

	var sr domain.SubmissionRepository
	sr = infra.NewSubmissionRepository(db.NewGit(), db.NewFileSystem(), infra.NewScraper(collector))

	var au usecase.AtcoderUseCase
	au = usecase.NewAtcoderUseCase(ac, sr)

	c := controller.NewController(au)

	if err := c.Do(); err != nil {
		logError.Printf("%+v\n", err)
	}

	logInfo.Println("cp-crawler finished.")
}
