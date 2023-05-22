// detail: https://atcoder.jp/contests/arc013/submissions/39770466
package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, m, l int
	fmt.Scan(&n, &m, &l)

	var p, q, r int
	fmt.Scan(&p, &q, &r)

	packingCount := func(a, b, c int) int {
		return (n / a) * (m / b) * (l / c)
	}

	fmt.Println(max(packingCount(p, q, r), packingCount(q, p, r)))
}
