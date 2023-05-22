// detail: https://atcoder.jp/contests/abc109/submissions/38758120
package main

import (
	"bufio"
	"fmt"
	"os"
)

type coord struct {
	x, y int
}

type coordPair struct {
	c1, c2 coord
}

func shortestPairList(h, w int, a [][]int) []coordPair {
	queue := make([]coord, 0, h*w)
	visited := make([][]bool, h)
	for i := range visited {
		visited[i] = make([]bool, w)
	}

	dy := []int{-1, 0, 1, 0}
	dx := []int{0, 1, 0, -1}

	isInside := func(co coord) bool {
		return 0 <= co.y && co.y < h && 0 <= co.x && co.x < w
	}

	queue = append(queue, coord{0, 0})
	visited[0][0] = true

	bfs := func(start coord) coordPair {
		for len(queue) > 0 {
			x, y := queue[0].x, queue[0].y
			queue = queue[1:]

			for i := 0; i < 4; i++ {
				ny := y + dy[i]
				nx := x + dx[i]

				if !isInside(coord{nx, ny}) {
					continue
				}

				if visited[ny][nx] {
					continue
				}

				if a[ny][nx]%2 == 1 {
					return coordPair{start, coord{nx, ny}}
				}

				queue = append(queue, coord{nx, ny})
				visited[ny][nx] = true
			}
		}

		return coordPair{}
	}

	pairList := make([]coordPair, 0, h*w)

	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if a[y][x]%2 == 1 {
				pair := bfs(coord{x, y})
				if (pair != coordPair{}) {
					pairList = append(pairList, pair)
				}
			}
		}
	}
	return pairList
}

type operation struct {
	start, goal coord
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func diffOne(s, g int) int {
	if s < g {
		return 1
	} else {
		return -1
	}
}

func toOperationList(pair coordPair) []operation {
	operationList := make([]operation, 0, abs(pair.c1.x-pair.c2.x)+abs(pair.c1.y-pair.c2.y))
	n := abs(pair.c1.x - pair.c2.x)
	for i := 0; i < n; i++ {
		diff := diffOne(pair.c1.x, pair.c2.x)

		operationList = append(operationList, operation{pair.c1, coord{pair.c1.x + diff, pair.c1.y}})
		pair.c1.x += diff
	}

	n = abs(pair.c1.y - pair.c2.y)
	for i := 0; i < n; i++ {
		diff := diffOne(pair.c1.y, pair.c2.y)
		operationList = append(operationList, operation{pair.c1, coord{pair.c1.x, pair.c1.y + diff}})
		pair.c1.y += diff
	}
	return operationList
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	stderr := bufio.NewWriter(os.Stderr)
	defer stdout.Flush()
	defer stderr.Flush()

	var h, w int
	fmt.Fscan(stdin, &h, &w)

	a := make([][]int, h)
	for i := range a {
		a[i] = make([]int, w)
		for j := range a[i] {
			fmt.Fscan(stdin, &a[i][j])
		}
	}

	pairList := shortestPairList(h, w, a)
	operationList := make([]operation, 0, h*w)
	for _, pair := range pairList {
		ol := toOperationList(pair)
		operationList = append(operationList, ol...)
	}

	fmt.Fprintln(stdout, len(operationList))
	for _, op := range operationList {
		fmt.Fprintf(stdout, "%d %d %d %d\n", op.start.y+1, op.start.x+1, op.goal.y+1, op.goal.x+1)
	}
}
