package atcoder

import (
	"context"
	"fmt"
	"sync"
	"time"

	model "github.com/matumoto1234/cp-crawler/domain/model"
	"github.com/matumoto1234/cp-crawler/domain/model/judge"
	"github.com/matumoto1234/cp-crawler/domain/repository"
)

var _ repository.Crawler = (*atcoderCrawlerImpl)(nil)

type fetcher interface {
	All(ctx context.Context) ([]submissionResponse, error)
}

type atcoderCrawlerImpl struct {
	f         fetcher
	once      sync.Once
	responses []submissionResponse
}

func NewAtcoderCrawler(f fetcher) *atcoderCrawlerImpl {
	return &atcoderCrawlerImpl{
		f: f,
	}
}

func min(a, b uint) uint {
	if a < b {
		return a
	}
	return b
}

// Do() : 提出一覧を取得し、その後pageNumber番目の提出情報を返す
//   - 1ページあたりの大きさはpageSize
//     [pageNumber * pageSize : (pageNumber + 1) * pageSize)]の範囲を取得する
func (ac *atcoderCrawlerImpl) Page(ctx context.Context, pageSize, pageNumber uint) (*model.Page[*model.Submission], error) {
	var err error

	ac.once.Do(func() {
		ac.responses, err = ac.f.All(ctx)
	})

	if err != nil {
		return nil, err
	}

	n := uint(len(ac.responses))

	// もしresponsesのサイズがpageSizeより小さい場合
	// pageSizeをresponsesのサイズに合わせる
	// TODO: もう少し良い実装がある気はする
	pageSize = min(pageSize, n)

	left := pageNumber * pageSize
	left = min(left, n)

	right := (pageNumber + 1) * pageSize
	right = min(right, n)

	// pageNumberによる指定ページのトリミング
	target := ac.responses[left:right]

	// 該当ページをドメインモデルに変換
	submissions := make([]*model.Submission, len(target))

	for i, v := range target {
		s, err := ac.toSubmission(ctx, v)

		if err != nil {
			return nil, err
		}

		submissions[i] = s
	}

	return model.NewPage(
		submissions,
		model.NewPaging(n),
	), nil
}

// AtCoder Problems APIから返ってくる提出のレスポンス
type submissionResponse struct {
	ID            int64   `json:"id"`
	EpochSecond   int64   `json:"epoch_second"`
	ProblemID     string  `json:"problem_id"`
	ContestID     string  `json:"contest_id"`
	UserID        string  `json:"user_id"`
	Language      string  `json:"language"`
	Point         float64 `json:"point"`
	Length        int64   `json:"length"`
	Result        string  `json:"result"`
	ExecutionTime int64   `json:"execution_time"`
}

// AtCoder Problems APIからは、AtCoderからスクレイピングした文字列をそのままJSONとして返している
// そのため、AtCoderのジャッジステータスとして明言されているものをここでは使用する
//   - https://atcoder.jp/contests/abc074/glossary?lang=ja
func toJudgeStatus(result string) judge.Status {
	switch result {
	case "AC":
		return judge.Accepted
	case "WA":
		return judge.WrongAnswer
	case "TLE":
		return judge.TimeLimitExceeded
	case "MLE":
		return judge.MemoryLimitExceeded
	case "RE":
		return judge.RuntimeError
	case "OLE":
		return judge.OutputLimitExceeded
	case "CE":
		return judge.CompilationError
	case "IE":
		return judge.InternalError
	}

	return judge.InternalError
}

func (ac *atcoderCrawlerImpl) toSubmission(ctx context.Context, res submissionResponse) (*model.Submission, error) {
	url, err := model.NewAtcoderSubmissionURL(res.ContestID, fmt.Sprint(res.ID))
	if err != nil {
		return nil, err
	}

	return model.NewSubmission(
		model.SiteAtcoder,
		res.ProblemID,
		fmt.Sprint(res.ID),
		res.ContestID,
		toJudgeStatus(res.Result),
		res.Language,
		time.Unix(res.EpochSecond, 0),
		url,
	), nil
}
