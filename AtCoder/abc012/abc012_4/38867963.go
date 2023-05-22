// detail: https://atcoder.jp/contests/abc012/submissions/38867963
package main

import (
	"bufio"
	"fmt"
	"os"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	stderr := bufio.NewWriter(os.Stderr)
	defer stdout.Flush()
	defer stderr.Flush()

	var n, m int
	fmt.Fscan(stdin, &n, &m)

	INF := 1 << 60

	// adjacency matrix
	am := make([][]int, n)
	for i := 0; i < n; i++ {
		am[i] = make([]int, n)
		for j := 0; j < n; j++ {
			am[i][j] = INF
            if i == j {
                am[i][j] = 0
            }
		}
	}


	for i := 0; i < m; i++ {
		var a, b, t int
		fmt.Fscan(stdin, &a, &b, &t)
		a--
		b--
		am[a][b] = t
		am[b][a] = t
	}

	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				am[i][j] = min(am[i][j], am[i][k]+am[k][j])
			}
		}
	}

	ans := INF

	for start := 0; start < n; start++ {
		maxDist := 0
		for goal := 0; goal < n; goal++ {
			maxDist = max(maxDist, am[start][goal])
		}

		ans = min(ans, maxDist)
	}

	fmt.Fprintln(stdout, ans)
}
