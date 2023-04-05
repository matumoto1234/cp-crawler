package db_test

import (
	"testing"

	"github.com/matumoto1234/cp-crawler/domain/model"
	"github.com/matumoto1234/cp-crawler/infra/db"
)

func Test_FileSystem_Dir(t *testing.T) {
	t.Parallel()

	tests := []struct {
		name      string
		site      model.Site
		problemID string
		want      string
		wantErr   bool
	}{
		{
			name:      "AtCoder",
			site:      model.SiteAtcoder,
			problemID: "abc001",
			want:      "../AtCoder/abc001",
			wantErr:   false,
		},
	}

	for _, test := range tests {
		test := test

		t.Run(test.name, func(t *testing.T) {
			t.Parallel()

			f := db.NewFileSystem()

			got, err := f.Dir(test.site, test.problemID)
			if (err != nil) != test.wantErr {
				t.Fatalf("Dir() error = %v, wantErr %v", err, test.wantErr)
			}

			if got != test.want {
				t.Fatalf("Dir() got = %v, want %v", got, test.want)
			}
		})
	}
}
