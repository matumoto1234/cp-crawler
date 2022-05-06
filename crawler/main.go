package main

import (
	"github.com/matumoto1234/cp-crawler/model"
	"github.com/matumoto1234/cp-crawler/controller"
	"github.com/matumoto1234/cp-crawler/repository"
	"github.com/matumoto1234/cp-crawler/service"
	"github.com/matumoto1234/cp-crawler/usecase"
	"github.com/matumoto1234/cp-crawler/variables"
)

func main() {
	l := model.NewInfoLogger()
	l.Println("cp-crawler start.")

	// if err := repository.InitGit(); err != nil {
	// 	l.Fatalf("%+v\n", err)
	// }

	as := service.NewAtCoderService(variables.AtCoderProblemsAPIBaseURL)
	au := usecase.NewAtCoderUseCase(as)

	sc := controller.NewSubmissionsController(au)

	subs, err := sc.GetSubmissions()
	if err != nil {
		l.Fatalf("%+v\n", err)
	}

	w := controller.NewWriter()

	for _, sub := range subs {
		if err := w.Write(sub); err != nil {
			l.Fatalf("%+v\n", err)
			continue
		}
		l.Printf("appended %v\n", sub.SubmissionURL)
	}

	if err = repository.PushChange(); err != nil {
		l.Fatalf("%+v\n", err)
	}

	l.Println("cp-crawler end.")
}
