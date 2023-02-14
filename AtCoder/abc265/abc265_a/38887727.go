// detail: https://atcoder.jp/contests/abc265/submissions/38887727
package main

import "fmt"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var x, y, n int
	fmt.Scan(&x, &y, &n)

	INF := 1 << 60
	ans := INF
	for yCount:=0;yCount<=n;yCount++ {
		if yCount * 3 > n {
			break
		}

		xCount := n - 3 * yCount
		price := xCount * x + yCount * y
		ans = min(ans, price)
	}

	fmt.Println(ans)
}
