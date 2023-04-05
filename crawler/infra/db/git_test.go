package db

import (
	"testing"
)

func Test_Git_execute(t *testing.T) {
	if err := execute("--help"); err != nil {
		t.Fatalf("execute() error = %v", err)
	}
}
