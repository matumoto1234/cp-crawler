package infra

import (
	"context"
	"os"
	"path/filepath"

	model "github.com/matumoto1234/cp-crawler/domain/model"
)

type RepositoryManagerImpl struct {
	f FileSystem
}

func NewRepositoryManager(f FileSystem) *RepositoryManagerImpl {
	return &RepositoryManagerImpl{
		f: f,
	}
}

func (m RepositoryManagerImpl) Exists(ctx context.Context, s *model.Submission) (bool, error) {
	dir, err := m.f.Dir(s.SiteID, s.ProblemID, s.ContestID)
	if err != nil {
		return false, err
	}

	fileName, err := m.f.FileName(s.Language, s.SubmissionID)
	if err != nil {
		return false, err
	}

	path := filepath.Join(dir, fileName)

	_, err = os.Stat(path)

	return !os.IsNotExist(err), nil
}
