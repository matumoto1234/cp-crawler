package domain

import (
	"net/url"
	"time"

	"github.com/pkg/errors"
)

// Entity
type Submission struct {
	SiteID        Site
	ProblemID     string
	SubmissionID  string
	Status        JudgeStatus
	Language      string
	SubmittedAt   time.Time
	SubmissionURL *url.URL
	SourceCode    string
}

func NewSubmission(
	siteID Site,
	problemID string,
	submissionID string,
	status JudgeStatus,
	language string,
	submittedAt time.Time,
	submissionURL *url.URL,
	sourceCode string,
) *Submission {
	return &Submission{
		SiteID:        siteID,
		ProblemID:     problemID,
		SubmissionID:  submissionID,
		Status:        status,
		Language:      language,
		SubmittedAt:   submittedAt,
		SubmissionURL: submissionURL,
		SourceCode:    sourceCode,
	}
}

func NewAtcoderSubmissionURL(contestID, submissionID string) (*url.URL, error) {
	url, err := url.Parse("https://atcoder.jp/contests/" + contestID + "/submissions/" + submissionID)

	if err != nil {
		return nil, errors.WithStack(err)
	}

	return url, nil
}
