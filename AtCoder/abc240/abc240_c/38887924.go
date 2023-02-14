// detail: https://atcoder.jp/contests/abc240/submissions/38887924
package main

import "fmt"

func main() {
	var n, x int
	fmt.Scan(&n, &x)

	abList := make([][2]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&abList[i][0], &abList[i][1])
	}

	dp := make([][]bool, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]bool, x+1)
	}
	dp[0][0] = true

	for i := 0; i < n; i++ {
		a, b := abList[i][0], abList[i][1]
		for j := 0; j <= x; j++ {
			if j+a <= x {
				dp[i+1][j+a] = dp[i+1][j+a] || dp[i][j]
			}
			if j+b <= x {
				dp[i+1][j+b] = dp[i+1][j+b] || dp[i][j]
			}
		}
	}

	if dp[n][x] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
