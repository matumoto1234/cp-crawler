package mock

import (
	"context"

	"github.com/matumoto1234/cp-crawler/domain/model"
)

type MockRepositoryManager struct {
	FakeExists func(ctx context.Context, s *model.Submission) (bool, error)
}

func (m *MockRepositoryManager) Exists(ctx context.Context, s *model.Submission) (bool, error) {
	return m.FakeExists(ctx, s)
}
