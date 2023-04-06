package mock

import (
	"context"
	"net/url"
)

type MockScraper struct {
	FakeSourceCode func(ctx context.Context, submissionURL *url.URL) (string, error)
}

func (m MockScraper) SourceCode(ctx context.Context, submissionURL *url.URL) (string, error) {
	return m.FakeSourceCode(ctx, submissionURL)
}
