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

func NewGit() *gitImpl {
	initConfig()
	return &gitImpl{}
}

func (g gitImpl) Add(path string) error {
	if err := execute("git", "add", path); err != nil {
		return err
	}

	return nil
}

func (g gitImpl) Commit(commitMsg string, dateTime time.Time) error {
	dateMsg := fmt.Sprintf("--date=\"%v\"", dateTime.String())

	if err := execute("git", "commit", "-m", commitMsg, dateMsg); err != nil {
		return err
	}

	return nil
}

func (g gitImpl) Push() error {
	if err := execute("git", "push", "origin", "HEAD"); err != nil {
		return err
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
	})
	return errors.WithStack(initErr)
}

func execute(arg ...string) error {
	cmd := exec.Command("", arg...)

	stdoutStderr, err := cmd.CombinedOutput()
	if err != nil {
		return errors.New(fmt.Sprintf("failed running the command %v\n command stdout and stderr output : %v\n", arg, stdoutStderr))
	}

	return nil
}
