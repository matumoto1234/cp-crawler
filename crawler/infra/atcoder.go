package infra

import (
	"context"
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"net/url"
	"sync"
	"time"

	model "github.com/matumoto1234/cp-crawler/domain/model"
	"github.com/matumoto1234/cp-crawler/domain/model/judge"
	variable "github.com/matumoto1234/cp-crawler/domain/variable"
	"github.com/pkg/errors"
)

type atcoderCrawlerImpl struct {
	client       *http.Client
	once         sync.Once
	responseList []atcoderSubmissionAPIResponse
}

func NewAtcoderCrawler(client *http.Client) *atcoderCrawlerImpl {
	return &atcoderCrawlerImpl{
		client: client,
	}
}

// Do() : 提出一覧を取得し、その後pageNumber番目の提出情報を返す
// - 1ページあたりの大きさはpageSize
func (ac atcoderCrawlerImpl) Do(ctx context.Context, pageSize, pageNumber int) (*model.Page[*model.Submission], error) {
	var err error
	ac.once.Do(func() {
		ac.responseList, err = fetchAtcoderSubmissionAPIResponseList(ctx, ac.client)
	})
	if err != nil {
		return nil, err
	}

	if len(ac.responseList) == 0 {
		return nil, errors.New("no submission")
	}

	min := func(a, b int) int {
		if a < b {
			return a
		}
		return b
	}

	if pageSize <= 0 {
		return nil, errors.New("invalid page size")
	}

	// 大きすぎるページサイズを調整
	pageSize = min(pageSize, len(ac.responseList))

	left := pageNumber * pageSize
	left = min(left, len(ac.responseList))

	right := (pageNumber + 1) * pageSize
	right = min(right, len(ac.responseList))

	if left < 0 || right < 0 {
		return nil, errors.New(fmt.Sprintf("invalid page number. page number : %d, page size : %d", pageNumber, pageSize))
	}

	totalCount := len(ac.responseList)

	// pageNumberによる指定ページのトリミング
	ac.responseList = ac.responseList[left:right]

	// 該当ページをドメインモデルに変換
	submissionList := make([]*model.Submission, len(ac.responseList))
	for i, resp := range ac.responseList {
		s, err := ac.convertToSubmission(ctx, resp)
		if err != nil {
			return nil, err
		}
		submissionList[i] = s
	}

	return model.NewPage(
		submissionList,
		model.NewPaging(pageSize, totalCount),
	), nil
}

func fetchAtcoderSubmissionAPIResponseList(ctx context.Context, httpClient *http.Client) ([]atcoderSubmissionAPIResponse, error) {
	u, err := url.Parse("https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions")
	if err != nil {
		return nil, errors.WithStack(err)
	}

	q := u.Query()
	q.Set("user", variable.AtCoderUserName)
	q.Set("from_second", "0")
	u.RawQuery = q.Encode()

	allResponseList := make([]atcoderSubmissionAPIResponse, 0)

	// ページネーションされているレスポンスをすべて取得する
	// 1ユーザーの全提出数は多くても10,000件程度かつ、提出URLなどしか持たないのでメモリに乗る
FETCH_LOOP:
	for {
		req, err := http.NewRequestWithContext(ctx, http.MethodGet, u.String(), nil)
		if err != nil {
			return nil, errors.Wrap(err, fmt.Sprintf("failed to create request. url : %s", u.String()))
		}

		resp, err := httpClient.Do(req)
		if err != nil {
			return nil, errors.Wrap(err, fmt.Sprintf("failed to send request. url : %s", u.String()))
		}
		defer resp.Body.Close()

		switch resp.StatusCode {
		case http.StatusOK:
			body, err := io.ReadAll(resp.Body)
			if err != nil {
				return nil, errors.Wrap(err, "failed to read response body")
			}

			var responseList []atcoderSubmissionAPIResponse
			if err := json.Unmarshal(body, &responseList); err != nil {
				return nil, errors.Wrap(err, fmt.Sprintf("failed to unmarshal response body: %v", string(body)))
			}

			if len(responseList) == 0 {
				break FETCH_LOOP
			}

			allResponseList = append(allResponseList, responseList...)

			// 取得した中で最新の提出時刻+1を次のリクエストで利用する
			newSecond := responseList[len(responseList)-1].EpochSecond + 1
			q := u.Query()
			q.Set("from_second", fmt.Sprint(newSecond))
			u.RawQuery = q.Encode()
		case http.StatusBadRequest:
			return nil, errors.New(fmt.Sprintf("bad request. URL: %s", u.String()))
		case http.StatusNotFound:
			return nil, errors.New(fmt.Sprintf("not found. URL: %s", u.String()))
		default:
			return nil, errors.New(fmt.Sprintf("unexpected status code: %d, URL: %s", resp.StatusCode, u.String()))
		}
	}
	return allResponseList, nil
}

// AtCoder Problems APIから返ってくる提出のレスポンス
type atcoderSubmissionAPIResponse struct {
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

func (ac atcoderCrawlerImpl) convertToSubmission(ctx context.Context, res atcoderSubmissionAPIResponse) (*model.Submission, error) {
	url, err := model.NewAtcoderSubmissionURL(res.ContestID, fmt.Sprint(res.ID))
	if err != nil {
		return nil, err
	}

	// AtCoder Problems APIからは、AtCoderからスクレイピングした文字列をそのままJSONとして返している
	// そのため、AtCoderのジャッジステータスとして明言されているものをここでは使用する
	//   - https://atcoder.jp/contests/abc074/glossary?lang=ja
	toJudgeStatus := func(result string) judge.Status {
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

	return model.NewSubmission(
		model.SiteAtcoder,
		res.ProblemID,
		fmt.Sprint(res.ID),
		toJudgeStatus(res.Result),
		res.Language,
		time.Unix(res.EpochSecond, 0),
		url,
	), nil
}
