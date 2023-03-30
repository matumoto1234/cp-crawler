// detail: https://atcoder.jp/contests/abc242/submissions/40165971
package main

import (
	"fmt"
	"sort"
)

func main() {
	var s string
	fmt.Scan(&s)

	r := []rune(s)

	sort.Slice(r, func(i, j int) bool {
		return r[i] < r[j]
	})

	fmt.Println(string(r))
}
