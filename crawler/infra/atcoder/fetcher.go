package atcoder

import (
	"context"
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"net/url"
	"os"
	"path/filepath"

	variable "github.com/matumoto1234/cp-crawler/domain/variable"
	"github.com/pkg/errors"
	"gopkg.in/dnaeon/go-vcr.v3/cassette"
	"gopkg.in/dnaeon/go-vcr.v3/recorder"
)

var _ fetcher = (*fetcherImpl)(nil)

type fetcherImpl struct {
	c *http.Client
	r *recorder.Recorder
}

func NewFetcher(c *http.Client, r *recorder.Recorder) *fetcherImpl {
	r.SetRealTransport(c.Transport)
	c.Transport = r

	return &fetcherImpl{
		c: c,
		r: r,
	}
}

// All() : ページネーションされているレスポンスをすべて取得する
// APIからのレスポンスはキャッシュしておき、最新の変更があった分だけ更新する
func (f *fetcherImpl) All(ctx context.Context) ([]submissionResponse, error) {
	u, err := url.Parse("https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions")
	if err != nil {
		return nil, errors.WithStack(err)
	}

	q := u.Query()
	q.Set("user", variable.AtCoderUserName)
	q.Set("from_second", "0")
	u.RawQuery = q.Encode()

	// 1ユーザーの全提出数は多くても10,000件程度かつ、提出URLなどしか持たないのでメモリに乗る
	allResponses := make([]submissionResponse, 0)

	for {
		resps, err := f.requestGET(ctx, u)
		if err != nil {
			return nil, err
		}

		if len(resps) == 0 {
			break
		}

		allResponses = append(allResponses, resps...)

		// 取得した中で最新の提出時刻+1を次のリクエストで利用する
		newSecond := resps[len(resps)-1].EpochSecond + 1
		q := u.Query()
		q.Set("from_second", fmt.Sprint(newSecond))
		u.RawQuery = q.Encode()
	}

	resp, err := f.updateLastInteraction(ctx)
	if err != nil {
		return nil, err
	}

	allResponses = append(allResponses, resp...)

	return allResponses, nil
}

// updateLastInteraction() : カセットの最後のリクエストを更新する
func (f *fetcherImpl) updateLastInteraction(ctx context.Context) ([]submissionResponse, error) {
	// カセットの競合を防ぐためStop
	f.r.Stop()

	// TODO: このcassetteNameはどうにかして引数にしたい
	cassetteName := filepath.Join(".cassette", "crawl")

	c, err := cassette.Load(cassetteName)
	if err != nil {
		wd, _ := os.Getwd()
		return nil, errors.Wrap(err, "failed to load cassette. working directory : "+wd)
	}

	// 空でない最後のリクエストを更新する(それ以降のリクエストを削除して新たにリクエストを送る)
	var last *cassette.Interaction
	for i := len(c.Interactions) - 1; i >= 0; i-- {
		if c.Interactions[i].Response.Body == "[]" {
			continue
		}
		last = c.Interactions[i]
		c.Interactions = c.Interactions[:i]
		break
	}

	if err := c.Save(); err != nil {
		return nil, errors.WithStack(err)
	}

	req, err := last.GetHTTPRequest()
	if err != nil {
		return nil, errors.WithStack(err)
	}

	respList, err := f.requestGET(ctx, req.URL)
	if err != nil {
		return nil, err
	}

	return respList, nil
}

func (f *fetcherImpl) requestGET(ctx context.Context, u *url.URL) ([]submissionResponse, error) {
	req, err := http.NewRequestWithContext(ctx, http.MethodGet, u.String(), nil)
	if err != nil {
		return nil, errors.Wrap(err, fmt.Sprintf("failed to create request. url : %s", u.String()))
	}

	resp, err := f.c.Do(req)
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

		var subResps []submissionResponse
		if err := json.Unmarshal(body, &subResps); err != nil {
			return nil, errors.Wrap(err, fmt.Sprintf("failed to unmarshal response body: %v", string(body)))
		}

		return subResps, nil
	default:
		return nil, errors.New(fmt.Sprintf("failed to fetch. status code: %d, URL: %s", resp.StatusCode, u.String()))
	}
}
