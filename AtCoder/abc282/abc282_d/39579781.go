// detail: https://atcoder.jp/contests/abc282/submissions/39579781
package main

import (
	"bufio"
	"fmt"
	"os"
)

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

	// connected component list
	CCList := make([][]int, 0)
	vertexToCCListIndex := make(map[int]int)

	q := make([]int, 0, n)
	visited := make([]bool, n)

	bfs := func(s int) {
		q = append(q, s)
		visited[s] = true
		colorList[s] = Black

		// connected component
		cc := make([]int, 0)

		for len(q) > 0 {
			v := q[0]
			q = q[1:]

			cc = append(cc, v)

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

		CCList = append(CCList, cc)

		for _, v := range cc {
			vertexToCCListIndex[v] = len(CCList) - 1
		}
	}

	for s := 0; s < n; s++ {
		if visited[s] {
			continue
		}
		bfs(s)
	}

	// 連結成分ごとの黒頂点の個数
	blackCountList := make([]int, len(CCList))
	for v, color := range colorList {
		if color == White {
			continue
		}

		ccIdx := vertexToCCListIndex[v]
		blackCountList[ccIdx]++
	}

	var ans int
	for v := 0; v < n; v++ {
		if colorList[v] == White {
			// ans += 同じ連結成分の黒の数 - len(adjList[v])
			//     += N - 同じ連結成分の頂点数
			ccIdx := vertexToCCListIndex[v]
			ans += blackCountList[ccIdx] - len(adjList[v]) + n - len(CCList[ccIdx])
		}
	}
	fmt.Println(ans)
}
