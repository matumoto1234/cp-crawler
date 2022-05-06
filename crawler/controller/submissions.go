package controller

import (
	"github.com/matumoto1234/cp-crawler/model"
	"github.com/matumoto1234/cp-crawler/usecase"
)

type SubmissionsController interface {
	GetSubmissions() ([]*model.Submission, error)
}

type submissionsControllerImpl struct {
	au usecase.AtCoderUseCase
}

func (sc *submissionsControllerImpl) GetSubmissions() ([]*model.Submission, error) {
	allSubs := make([]*model.Submission, 0)

	atcoderSubs, err := sc.au.GetSubmissions()
	if err != nil {
		return nil, err
	}
	allSubs = append(allSubs, atcoderSubs...)

	return allSubs, nil
}

func NewSubmissionsController(au usecase.AtCoderUseCase) SubmissionsController {
	return &submissionsControllerImpl{
		au: au,
	}
}
