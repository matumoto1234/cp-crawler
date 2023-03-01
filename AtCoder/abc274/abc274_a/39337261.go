// detail: https://atcoder.jp/contests/abc274/submissions/39337261
package main

import (
	"fmt"
	"math"
	"strconv"
)

// prec: 少数精度 (小数部を最大何桁で表示したいか)
// rounded: 四捨五入するかどうか
func FloatFormatWithMaxPrecision(f float64, prec int, rounded bool) string {
	if !rounded {
		// 四捨五入しない場合、先に切り捨てをしておく。
		e := math.Pow10(prec)
		f = math.Floor(f*e) / e
	}

	// 書式化
	s := strconv.FormatFloat(f, 'f', prec, 64)

	return s
}

func main() {
	var a, b float64
	fmt.Scan(&a, &b)

	fmt.Println(FloatFormatWithMaxPrecision(b/a, 3, true))
}
