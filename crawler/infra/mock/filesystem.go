package mock

import "github.com/matumoto1234/cp-crawler/domain/model"

type MockFileSystem struct {
	FakeFileName  func(lang, submissionID string) (string, error)
	FakeDir       func(siteID model.Site, problemID, contestID string) (string, error)
	FakeWriteFile func(dir, fileName string, content []byte) error
}

func (m MockFileSystem) FileName(lang, submissionID string) (string, error) {
	return m.FakeFileName(lang, submissionID)
}

func (m MockFileSystem) Dir(siteID model.Site, problemID, contestID string) (string, error) {
	return m.FakeDir(siteID, problemID, contestID)
}

func (m MockFileSystem) WriteFile(dir, fileName string, content []byte) error {
	return m.FakeWriteFile(dir, fileName, content)

}
