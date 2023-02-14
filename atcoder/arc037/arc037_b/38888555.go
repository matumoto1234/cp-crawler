// detail: https://atcoder.jp/contests/arc037/submissions/38888555
package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	graph := make([][]int, n)

	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scan(&u, &v)

		u--
		v--

		graph[u] = append(graph[u], v)
		graph[v] = append(graph[v], u)
	}

	visited := make([]bool, n)
	// connected component
	// if cc[i] == cc[j], node i and node j are in the same connected component
	cc := make([]int, n)
	ccID := 0

	// isTree
	isTree := make([]bool, n)
	for i:=0;i<n;i++ {
		isTree[i] = true
	}

	var dfs func(v, par int)
	dfs = func(v, par int) {
		visited[v] = true
		cc[v] = ccID

		for _, to := range graph[v] {
			if to == par {
				continue
			}

			if visited[to] {
				isTree[ccID] = false
				continue
			}
			dfs(to, v)
		}
	}

	for s := 0; s < n; s++ {
		if visited[s] {
			continue
		}

		dfs(s, -1)
		ccID++
	}

	isTree = isTree[:ccID]

	treeCount := 0
	for _, is := range isTree {
		if is {
			treeCount++
		}
	}

	fmt.Println(treeCount)
}
