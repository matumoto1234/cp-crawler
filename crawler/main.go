package main

import (
	"log"
	"net/http"
	"os"
	"path/filepath"
	"time"

	"github.com/gocolly/colly"
	"github.com/matumoto1234/cp-crawler/controller"
	"github.com/matumoto1234/cp-crawler/domain/repository"
	"github.com/matumoto1234/cp-crawler/infra"
	"github.com/matumoto1234/cp-crawler/infra/atcoder"
	"github.com/matumoto1234/cp-crawler/infra/db"
	"github.com/matumoto1234/cp-crawler/usecase"
	"golang.org/x/time/rate"
	"gopkg.in/dnaeon/go-vcr.v3/recorder"
)

func main() {
	logInfo := log.New(os.Stdout, "[INFO] ", log.LstdFlags)
	logError := log.New(os.Stderr, "[WARN] ", log.LstdFlags)

	logInfo.Println("cp-crawler started.")

	lt := infra.NewLoggingTransport(
		http.DefaultTransport,
		logInfo,
	)

	rlt := infra.NewRateLimitTransport(
		lt,
		rate.NewLimiter(rate.Every(2*time.Second), 1), // 1 request every 2 seconds
	)

	r, err := recorder.NewWithOptions(&recorder.Options{
		CassetteName: filepath.Join(".cassette", "crawl"),
		Mode:         recorder.ModeReplayWithNewEpisodes,
	})
	if err != nil {
		logError.Fatalf("%+v\n", err)
	}

	r.SetReplayableInteractions(true)

	client := &http.Client{
		Transport: rlt,
	}

	var ac repository.Crawler = atcoder.NewAtcoderCrawler(client, r)

	collector := colly.NewCollector()

	collector.Limit(&colly.LimitRule{
		DomainGlob:  "*atcoder.jp*",
		RandomDelay: 5 * time.Second,
	})

	g, err := db.NewGit()
	if err != nil {
		logError.Printf("%+v\n", err)
	}

	f := db.NewFileSystem()

	var sr repository.SubmissionRepository = infra.NewSubmissionRepository(g, f, atcoder.NewScraper(collector), infra.NewRepositoryManager(f))

	var au usecase.AtcoderUseCase = usecase.NewAtcoderUseCase(ac, sr)

	c := controller.NewController(au)

	if err := c.Do(); err != nil {
		logError.Printf("%+v\n", err)
	}

	logInfo.Println("cp-crawler finished.")
}
