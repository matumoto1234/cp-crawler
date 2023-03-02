// detail: https://atcoder.jp/contests/abc031/submissions/39356902
package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var a, d int
	fmt.Scan(&a, &d)

	fmt.Println(max((a+1)*d, a*(d+1)))
}
