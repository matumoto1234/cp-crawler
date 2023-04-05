package mock

import "time"

type MockGit struct {
	FakeAdd    func(path string) error
	FakeCommit func(commitMsg string, dateTime time.Time) error
	FakePush   func() error
}

func (m MockGit) Add(path string) error {
	return m.FakeAdd(path)
}

func (m MockGit) Commit(commitMsg string, dateTime time.Time) error {
	return m.FakeCommit(commitMsg, dateTime)
}

func (m MockGit) Push() error {
	return m.FakePush()
}
