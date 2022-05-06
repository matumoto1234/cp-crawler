package variables

import (
	"os"
	"fmt"
)

const (
	AtCoderUserName = "matumoto"
	AOJUserName = "s1280136"

	GitUserName = "crawler"
	GitRepositoryName = "cp-crawler"
	GitHubUserName = "matumoto1234"
	AtCoderProblemsAPIBaseURL = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user=%v&from_second=%v"
)

var (
	GitEMail = os.Getenv("GIT_EMAIL")
	GitHubToken = os.Getenv("GITHUB_TOKEN")
	GitRemoteURL = fmt.Sprintf("https://%v:%v@github.com/%v/%v.git", GitHubUserName, GitHubToken, GitHubUserName, GitRepositoryName)
)
