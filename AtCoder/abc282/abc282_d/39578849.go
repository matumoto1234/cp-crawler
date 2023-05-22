// detail: https://atcoder.jp/contests/abc282/submissions/39578849
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

	var n, m int
	fmt.Fscan(stdin, &n, &m)

	edgeList := make([][2]int, m)

	// 隣接リスト
	adjList := make([][]int, n)
	for i := range edgeList {
		var u, v int
		fmt.Fscan(stdin, &u, &v)

		u--
		v--

		edgeList[i][0] = u
		edgeList[i][1] = v
		adjList[u] = append(adjList[u], v)
		adjList[v] = append(adjList[v], u)
	}

	type Color int
	const (
		Black = iota
		White
		Unknown
	)
	colorList := make([]Color, n)
	for i := range colorList {
		colorList[i] = Unknown
	}

	q := make([]int, 0, n)
	visited := make([]bool, n)

	bfs := func(s int) {
		q = append(q, s)
		visited[s] = true
		colorList[s] = Black

		for len(q) > 0 {
			v := q[0]
			q = q[1:]

			for _, to := range adjList[v] {
				if colorList[v] == colorList[to] {
					fmt.Println(0)
					os.Exit(0)
				}
				if visited[to] {
					continue
				}
				if colorList[v] == Black {
					colorList[to] = White
				} else {
					colorList[to] = Black
				}
				q = append(q, to)
				visited[to] = true
			}
		}
	}

	for s := 0; s < n; s++ {
		if visited[s] {
			continue
		}
		bfs(s)
	}

	blackCount := 0
	for _, color := range colorList {
		if color == Black {
			blackCount++
		}
		if color == Unknown {
			panic("RE")
		}
	}

	var ans int
	for v := 0; v < n; v++ {
		if colorList[v] == White {
			ans += blackCount - len(adjList[v])
		}
	}
	fmt.Println(ans)
}
