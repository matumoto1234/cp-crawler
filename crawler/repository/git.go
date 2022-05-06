package repository

import (
	"fmt"
	"io/ioutil"
	"os"
	"os/exec"
	"path"
	"time"

	"github.com/pkg/errors"

	"github.com/matumoto1234/cp-crawler/variables"
)

func git(arg ...string) error {
	err := exec.Command("git", arg...).Run()
	if err != nil {
		return errors.New(fmt.Sprintf("git: run the command [git %v]\n", arg))
	}
	return nil
}

func InitGit() error {
	if err := git("config", "user.name", variables.GitUserName); err != nil {
		return err
	}

	if err := git("config", "user.email", variables.GitEMail); err != nil {
		return err
	}

	if err := git("config", "commit.gpgsign", "false"); err != nil {
		return err
	}

	if err := git("remote", "set-url", "origin", variables.GitRemoteURL); err != nil {
		return err
	}

	if err := git("switch", "main"); err != nil {
		return err
	}
	return nil
}

func AppendSubmission(filePath string, content []byte, dateTime time.Time) error {
	directory := path.Dir(filePath)
	if !Exists(directory) {
		if err := os.MkdirAll(directory, 0755); err != nil {
			return errors.WithStack(err)
		}
	}
	if !Exists(directory) {
		return errors.New("AppendSubmission: Can not mkdir.")
	}
	if err := ioutil.WriteFile(filePath, content, 0755); err != nil {
		return errors.WithStack(err)
	}
	if err := git("add", fmt.Sprint(filePath)); err != nil {
		return err
	}
	commitMsg := fmt.Sprintf("\"add %v\"", filePath)
	dateMsg := fmt.Sprintf("--date=\"%v\"", dateTime.String())
	if err := git("commit", "-m", commitMsg, dateMsg); err != nil {
		return err
	}
	return nil
}

func PushChange() error {
	if err := git("push", "origin", "HEAD"); err != nil {
		return err
	}
	return nil
}
