// detail: https://atcoder.jp/contests/abc033/submissions/40315539
package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)

	exprList := strings.Split(s, "+")

	ans := 0

	for _, expr := range exprList {
		if !strings.Contains(expr, "0") {
			ans++
		}
	}

	fmt.Println(ans)
}
