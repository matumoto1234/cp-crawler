// detail: https://atcoder.jp/contests/abc277/submissions/39537536
package main

import (
	"bufio"
	"fmt"
	"os"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	stdin := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(stdin, &n)

	graph := make(map[int][]int)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Fscan(stdin, &a, &b)

		a--
		b--

		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}

	// BFS
	q := make([]int, 0, n)
	q = append(q, 0)

	visited := make(map[int]bool, n)
	visited[0] = true

	ans := 1

	for len(q) > 0 {
		v := q[0]
		q = q[1:]

		ans = max(ans, v+1)

		for _, to := range graph[v] {
			if visited[to] {
				continue
			}

			q = append(q, to)
			visited[to] = true
		}
	}

	fmt.Println(ans)
}
