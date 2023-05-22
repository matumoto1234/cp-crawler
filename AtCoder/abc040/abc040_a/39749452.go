// detail: https://atcoder.jp/contests/abc040/submissions/39749452
package main

import "fmt"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n, x int
	fmt.Scan(&n, &x)

	fmt.Println(min(n-x, x-1))
}
