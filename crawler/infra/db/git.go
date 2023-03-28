package db

import (
	"fmt"
	"os/exec"
	"sync"
	"time"

	variable "github.com/matumoto1234/cp-crawler/domain/variable"
	"github.com/pkg/errors"
)

// infra内でのGit処理を独立させた構造体
type Git struct {
}

func NewGit() *Git {
	initConfig()
	return &Git{}
}

func (g Git) Add(filePath string) error {
	if err := execute("git", "add", filePath); err != nil {
		return errors.WithStack(err)
	}

	return nil
}

func (g Git) Commit(commitMsg string, dateTime time.Time) error {
	dateMsg := fmt.Sprintf("--date=\"%v\"", dateTime.String())

	if err := execute("git", "commit", "-m", commitMsg, dateMsg); err != nil {
		return errors.WithStack(err)
	}

	return nil
}

func (g Git) Push() error {
	if err := execute("git", "push", "origin", "HEAD"); err != nil {
		return errors.WithStack(err)
	}

	return nil
}

var once sync.Once

func initConfig() error {
	var initErr error
	once.Do(func() {
		if err := execute("git", "config", "user.name", variable.GitUserName); err != nil {
			initErr = err
			return
		}

		if err := execute("git", "config", "user.email", variable.GitEMail); err != nil {
			initErr = err
			return
		}

		if err := execute("git", "remote", "set-url", "origin", variable.GitRemoteURL); err != nil {
			initErr = err
			return
		}

		if err := execute("git", "switch", "main"); err != nil {
			initErr = err
			return
		}
	})
	return errors.WithStack(initErr)
}

func execute(arg ...string) error {
	err := exec.Command("", arg...).Run()

	if err != nil {
		return errors.New(fmt.Sprintf("failed running the command %v\n", arg))
	}

	return nil
}
