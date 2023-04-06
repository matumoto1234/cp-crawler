package model

import (
	"net/url"
	"time"

	"github.com/matumoto1234/cp-crawler/domain/model/judge"
	"github.com/pkg/errors"
)

// Entity
// ソースコードはパフォーマンスの都合上持たせず、必要なときにスクレイピングして取得する
type Submission struct {
	SiteID        Site
	ProblemID     string
	SubmissionID  string
	ContestID     string
	Status        judge.Status
	Language      string
	SubmittedAt   time.Time
	SubmissionURL *url.URL
}

func NewSubmission(
	siteID Site,
	problemID string,
	submissionID string,
	contestID string,
	status judge.Status,
	language string,
	submittedAt time.Time,
	submissionURL *url.URL,
) *Submission {
	return &Submission{
		SiteID:        siteID,
		ProblemID:     problemID,
		SubmissionID:  submissionID,
		ContestID:     contestID,
		Status:        status,
		Language:      language,
		SubmittedAt:   submittedAt,
		SubmissionURL: submissionURL,
	}
}

func NewAtcoderSubmissionURL(contestID, submissionID string) (*url.URL, error) {
	url, err := url.Parse("https://atcoder.jp/contests/" + contestID + "/submissions/" + submissionID)

	if err != nil {
		return nil, errors.WithStack(err)
	}

	return url, nil
}
