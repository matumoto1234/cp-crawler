package infra

import (
	"context"

	model "github.com/matumoto1234/cp-crawler/domain/model"
	"github.com/matumoto1234/cp-crawler/infra/db"
	"github.com/pkg/errors"
)

type submissionRepositoryImpl struct {
	g *db.Git
	w *db.Writer
}

func NewSubmissionRepository(g *db.Git, w *db.Writer) *submissionRepositoryImpl {
	return &submissionRepositoryImpl{
		g: g,
		w: w,
	}
}

func (a submissionRepositoryImpl) Save(ctx context.Context, s *model.Submission) error {
	if err := a.w.Do(ctx, s); err != nil {
		return errors.WithStack(err)
	}

	fileName, err := a.w.FileName(s)
	if err != nil {
		return errors.WithStack(err)
	}

	path, err := a.w.DestinationPath(s)
	if err != nil {
		return errors.WithStack(err)
	}

	filePath := path + fileName

	if err := a.g.Add(filePath); err != nil {
		return errors.WithStack(err)
	}

	if err := a.g.Commit("add "+filePath, s.SubmittedAt); err != nil {
		return errors.WithStack(err)
	}

	if err := a.g.Push(); err != nil {
		return errors.WithStack(err)
	}

	return nil
}
