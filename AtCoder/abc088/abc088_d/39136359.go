// detail: https://atcoder.jp/contests/abc088/submissions/39136359
package main

import "fmt"

func main() {
	var h, w int
	fmt.Scan(&h, &w)

	s := make([]string, h)
	for i := 0; i < h; i++ {
		fmt.Scan(&s[i])
	}

	// bfs
	queue := make([][2]int, 0)
	queue = append(queue, [2]int{0, 0})

	distMatrix := make([][]int, h)
	for i := 0; i < h; i++ {
		distMatrix[i] = make([]int, w)
		for j := 0; j < w; j++ {
			distMatrix[i][j] = -1
		}
	}
	distMatrix[0][0] = 1

	dy := []int{0, 1, 0, -1}
	dx := []int{1, 0, -1, 0}

	for len(queue) > 0 {
		y, x := queue[0][0], queue[0][1]
		queue = queue[1:]

		for i := 0; i < 4; i++ {
			ny := y + dy[i]
			nx := x + dx[i]

			if ny < 0 || ny >= h || nx < 0 || nx >= w {
				continue
			}
			if s[ny][nx] == '#' {
				continue
			}
			if distMatrix[ny][nx] != -1 {
				continue
			}

			distMatrix[ny][nx] = distMatrix[y][x] + 1
			queue = append(queue, [2]int{ny, nx})
		}
	}

	if distMatrix[h-1][w-1] == -1 {
		fmt.Println(-1)
		return
	}

	blackCount := 0
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if s[i][j] == '#' {
				blackCount++
			}
		}
	}

	whiteCount := h*w - blackCount
	fmt.Println(whiteCount - distMatrix[h-1][w-1])
}
