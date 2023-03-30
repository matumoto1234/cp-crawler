// detail: https://atcoder.jp/contests/abc016/submissions/40166473
package main

import "fmt"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	const INF = 1 << 60

	adjMatrix := make([][]int, n)
	for i := 0; i < n; i++ {
		adjMatrix[i] = make([]int, n)
		for j := 0; j < n; j++ {
			if i == j {
				adjMatrix[i][j] = 0
				continue
			}
			adjMatrix[i][j] = INF
		}
	}

	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan(&a, &b)

		a--
		b--

		adjMatrix[a][b] = 1
		adjMatrix[b][a] = 1
	}

	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k]+adjMatrix[k][j])
			}
		}
	}

	for i := 0; i < n; i++ {
		cnt := 0

		for j := 0; j < n; j++ {
			if adjMatrix[i][j] == 2 {
				cnt++
			}
		}

		fmt.Println(cnt)
	}
}
