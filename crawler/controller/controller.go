package controller

import (
	"context"

	"github.com/matumoto1234/cp-crawler/usecase"
)

type CrawlerController struct {
	a usecase.AtcoderUseCase
}

func (c CrawlerController) Do() error {
	// TODO: CLIツールとして実行するようにする
	//       e.g. cp-crawler --site atcoder --user matumoto

	ctx := context.Background()
	return c.a.CrawlAndSave(ctx)
}

func NewController(a usecase.AtcoderUseCase) *CrawlerController {
	return &CrawlerController{
		a: a,
	}
}
