package usecase

import (
	"github.com/matumoto1234/cp-crawler/model"
	"github.com/matumoto1234/cp-crawler/service"
)

type AtCoderUseCase interface {
	GetSubmissions() ([]*model.Submission, error)
}

type atCoderUseCaseImpl struct {
	as service.AtCoderService
}

// The AtCoder Problems API will return up to 500 submissions after the specified time.
// So, If you want to get the all submissions, get each 500 submissions and change specified time.
func (au *atCoderUseCaseImpl) GetSubmissions() ([]*model.Submission, error) {
	unixTime := int64(0)

	allSubs := make([]*model.Submission, 0)

	for {
		url, err := au.as.MakeURL(unixTime)
		if err != nil {
			return nil, err
		}
		apis, err := au.as.FetchSubmissions(url)
		if err != nil {
			return nil, err
		}

		if len(apis) == 0 {
			break
		}

		subs, err := au.as.ConvertToSubmissions(apis)
		if err != nil {
			return nil, err
		}

		allSubs = append(allSubs, subs...)
		unixTime = subs[len(subs) - 1].SubmittedAt.Unix()
		unixTime++ // for next submissions
	}
	return allSubs, nil
}

func NewAtCoderUseCase(as service.AtCoderService) AtCoderUseCase {
	return &atCoderUseCaseImpl{
		as: as,
	}
}
