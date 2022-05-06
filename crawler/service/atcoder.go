package service

import (
	"encoding/json"
	"fmt"
	"io"
	"math/rand"
	"net/http"
	"net/url"
	"time"

	"github.com/gocolly/colly"
	"github.com/matumoto1234/cp-crawler/model"
	"github.com/matumoto1234/cp-crawler/variables"
	"github.com/pkg/errors"
)

type AtCoderService interface {
	MakeURL(unixTime int64) (*url.URL, error)
	FetchSubmissions(*url.URL) ([]*SubmissionAPI, error)
	ConvertToSubmissions([]*SubmissionAPI) ([]*model.Submission, error)
}

type SubmissionAPI struct {
	Id            int64   `json:"id"`
	EpochSecond   int64   `json:"epoch_second"`
	ProblemId     string  `json:"problem_id"`
	ContestId     string  `json:"contest_id"`
	UserId        string  `json:"user_id"`
	Language      string  `json:"language"`
	Point         float64 `json:"point"`
	Length        int64   `json:"length"`
	Result        string  `json:"result"`
	ExecutionTime int64   `json:"execution_time"`
}

func NewSubmissionAPIs(respBody []byte) ([]*SubmissionAPI, error) {
	var apiResults []*SubmissionAPI
	err := json.Unmarshal(respBody, &apiResults)
	if err != nil {
		return nil, errors.WithStack(err)
	}

	return apiResults, nil
}

type atCoderServiceImpl struct {
	baseAPIURL string
}


func (as *atCoderServiceImpl) MakeURL(unixTime int64) (*url.URL, error) {
	userName := variables.AtCoderUserName
	apiURLStr := fmt.Sprintf(as.baseAPIURL, userName, unixTime)
	return url.Parse(apiURLStr)
}

func (as *atCoderServiceImpl) FetchSubmissions(url *url.URL) ([]*SubmissionAPI, error) {
	res, err := http.Get(url.String())
	if err != nil {
		return nil, errors.WithStack(err)
	}
	defer res.Body.Close()

	if res.StatusCode != 200 {
		errMsg := fmt.Sprintf("fetchURL: %v", res.Status)
		return nil, errors.New(errMsg)
	}

	body, err := io.ReadAll(res.Body)
	if err != nil {
		return nil, errors.WithStack(err)
	}

	l := model.NewInfoLogger()
	l.Printf("fetched %v\n", url.String())

	rand.Seed(time.Now().UnixNano())
	wait := rand.Intn(3) + 1
	time.Sleep(time.Duration(wait) * time.Second)

	apiResults, err := NewSubmissionAPIs(body)
	if err != nil {
		return nil, err
	}

	return apiResults, nil
}

func convertToSubmission(api *SubmissionAPI) (*model.Submission, error) {
	submissionURL := fmt.Sprintf("https://atcoder.jp/contests/%v/submissions/%v", api.ContestId, api.Id)
	sourceCode, err := func() (string, error) {
		c := colly.NewCollector()

		sourceCode := ""

		c.OnHTML("body", func(e *colly.HTMLElement) {
			sourceCode = e.DOM.Find("#submission-code").Text()
		})

		err := c.Visit(submissionURL)
		if err != nil {
			return "", fmt.Errorf("url:%v %+v", submissionURL, errors.WithStack(err))
		}

		if sourceCode == "" {
			return "", errors.New("SourceCode: source code is empty.")
		}

		l := model.NewInfoLogger()
		l.Printf("scraped %v\n", submissionURL)
		time.Sleep(2 * time.Second)

		return sourceCode, nil
	}()

	if err != nil {
		return nil, err
	}

	return &model.Submission{
		SiteIdentifier:       "atcoder",
		ProblemIdentifier:    api.ContestId + "/" + api.ProblemId,
		SubmissionIdentifier: fmt.Sprint(api.Id),
		IsAccepted:           api.Result == "AC",
		Language:             api.Language,
		SubmittedAt:          time.Unix(api.EpochSecond, 0),
		SubmissionURL:        submissionURL,
		SourceCode:           sourceCode,
	}, nil
}

func (as *atCoderServiceImpl) ConvertToSubmissions(apis []*SubmissionAPI) ([]*model.Submission, error) {
	w := NewWriter()
	if err := w.AppendExistingFile("atcoder"); err != nil {
		return nil, err
	}

	subs := make([]*model.Submission, 0)
	for i, v := range apis {
		isLast := i == len(apis)-1
		isEmpty := len(subs) == 0
		ignorable := !(isLast && isEmpty)
		if ignorable && w.IsWrittenSub("atcoder", fmt.Sprint(v.Id)) {
			continue
		}
		sub, err := convertToSubmission(v)
		if err != nil {
			l := model.NewLogger("[warn]: ")
			l.Println(err)
			continue
		}
		subs = append(subs, sub)
	}
	return subs, nil
}

func NewAtCoderService(baseAPIURL string) AtCoderService {
	return &atCoderServiceImpl{
		baseAPIURL: baseAPIURL,
	}
}
