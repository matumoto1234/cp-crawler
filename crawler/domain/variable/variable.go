package domain

import (
	"fmt"
	"os"
)

const (
	AtCoderUserName           = "matumoto"
	AOJUserName               = "s1280136"
	GitUserName               = "crawler"
	GitRepositoryName         = "cp-crawler"
	GitHubUserName            = "matumoto1234"
)

var (
	GitEMail     = os.Getenv("GIT_EMAIL")
	GitHubToken  = os.Getenv("GITHUB_TOKEN")
	GitRemoteURL = fmt.Sprintf("https://%v:%v@github.com/%v/%v.git", GitHubUserName, GitHubToken, GitHubUserName, GitRepositoryName)
)
