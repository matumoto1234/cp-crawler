package service

import (
	"context"
	"net/url"
)

// メモ
// ドメインモデルのSourceCodeを取得したい
// → SourceCodeをそのままドメインモデルにのせるのは意味としては正しいが、
//   - ドメインモデルが重くなってしまう(パフォーマンスの犠牲)
//   - 取得にinfra側のスクレイピング処理などに依存してしまう(純粋性の犠牲)
//   これら2つの犠牲が発生してしまう
// そのため、ドメインモデルのソースコード取得をドメインサービスに切り分け、ドメインモデルの完全性を犠牲にしている

type Scraper interface {
	SourceCode(ctx context.Context, url *url.URL) (string, error)
}
