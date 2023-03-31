// detail: https://atcoder.jp/contests/abc285/submissions/40186558
package main

import (
	"bufio"
	"fmt"
	"os"
)

type Indexer struct {
	strToIndex map[string]int
	Count      int
}

func (i *Indexer) String(s string) int {
	idx, ok := i.strToIndex[s]
	if ok {
		return idx
	}

	i.strToIndex[s] = i.Count
	i.Count++
	return i.strToIndex[s]
}

func main() {
	stdin := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(stdin, &n)

	stList := make([][2]string, n)
	for i := 0; i < n; i++ {
		var s, t string
		fmt.Fscan(stdin, &s, &t)

		stList[i][0] = s
		stList[i][1] = t
	}

	indexer := Indexer{strToIndex: make(map[string]int)}
	for i := 0; i < n; i++ {
		s, t := stList[i][0], stList[i][1]

		_ = indexer.String(s)
		_ = indexer.String(t)
	}

	size := indexer.Count

	graph := make([][]int, size)
	inDegree := make([]int, size)
	for i := 0; i < n; i++ {
		s, t := stList[i][0], stList[i][1]

		sIdx := indexer.String(s)
		tIdx := indexer.String(t)

		graph[sIdx] = append(graph[sIdx], tIdx)
		inDegree[tIdx]++
	}

	q := make([]int, 0)
	for i := 0; i < len(inDegree); i++ {
		if inDegree[i] == 0 {
			q = append(q, i)
		}
	}

	isVisited := make([]bool, size)
	vList := make([]int, 0)

	for len(q) > 0 {
		v := q[0]
		q = q[1:]

		vList = append(vList, v)
		isVisited[v] = true

		for _, to := range graph[v] {
			if isVisited[to] {
				continue
			}
			inDegree[to]--
			if inDegree[to] == 0 {
				q = append(q, to)
			}
		}
	}

	if len(vList) != size {
		fmt.Println("No")
		return
	}

	fmt.Println("Yes")
}
