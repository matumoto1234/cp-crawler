package db

import (
	"fmt"
	"os/exec"
	"sync"
	"time"

	variable "github.com/matumoto1234/cp-crawler/domain/variable"
	"github.com/pkg/errors"
)

type gitImpl struct {
}

func NewGit() (*gitImpl, error) {
	if err := initConfig(); err != nil {
		return nil, err
	}
	return &gitImpl{}, nil
}

func (g gitImpl) Add(path string) error {
	if err := execute("add", path); err != nil {
		return err
	}

	return nil
}

func (g gitImpl) Commit(commitMsg string, dateTime time.Time) error {
	dateMsg := fmt.Sprintf("--date=\"%v\"", dateTime.String())

	if err := execute("commit", "-m", commitMsg, dateMsg); err != nil {
		return err
	}

	return nil
}

func (g gitImpl) Push() error {
	if err := execute("push", "origin", "HEAD"); err != nil {
		return err
	}

	return nil
}

var once sync.Once

func initConfig() error {
	var initErr error
	once.Do(func() {
		if err := execute("config", "user.name", variable.GitUserName); err != nil {
			initErr = err
			return
		}

		if err := execute("config", "user.email", variable.GitEMail); err != nil {
			initErr = err
			return
		}

		if err := execute("remote", "set-url", "origin", variable.GitRemoteURL); err != nil {
			initErr = err
			return
		}
	})
	return errors.WithStack(initErr)
}

func execute(arg ...string) error {
	cmd := exec.Command("git", arg...)

	stdoutStderr, err := cmd.CombinedOutput()
	if err != nil {
		return errors.New(fmt.Sprintf("failed running the command %v\n command stdout and stderr output : %s\n", arg, string(stdoutStderr)))
	}

	return nil
}
