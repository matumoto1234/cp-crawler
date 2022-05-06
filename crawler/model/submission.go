package model

import (
	"time"
)

type Submission struct {
	SiteIdentifier       string
	ProblemIdentifier    string
	SubmissionIdentifier string
	IsAccepted           bool
	Language             string
	SubmittedAt          time.Time
	SubmissionURL        string
	SourceCode           string
}
