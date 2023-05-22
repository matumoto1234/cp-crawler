// detail: https://atcoder.jp/contests/abc289/submissions/38806410
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	var m int
	fmt.Scan(&m)

	b := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&b[i])
	}

	bExists := make(map[int]bool)
	for _, bi := range b {
		bExists[bi] = true
	}

	var x int
	fmt.Scan(&x)

	limit := 2000000
	dp := make([]bool, limit)
	dp[0] = true

	for i := 0; i < limit/2; i++ {
		if !dp[i] {
			continue
		}

		for j := 0; j < n; j++ {
			next := i + a[j]
			if bExists[next] {
				continue
			}

			dp[next] = dp[i]
		}
	}

	if dp[x] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
