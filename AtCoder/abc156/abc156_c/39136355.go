// detail: https://atcoder.jp/contests/abc156/submissions/39136355
package main

import "fmt"

func dist(x, p int) int {
	return (x - p) * (x - p)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n int
	fmt.Scan(&n)

	xList := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&xList[i])
	}

	INF := 1 << 60
	ans := INF

	for p := 1; p <= 100; p++ {
		sum := 0
		for _, x := range xList {
			sum += dist(x, p)
		}
		ans = min(ans, sum)
	}

	fmt.Println(ans)
}
