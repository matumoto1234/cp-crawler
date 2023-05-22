// detail: https://atcoder.jp/contests/abc293/submissions/39727593
package main

import "fmt"

func main() {
	var h, w int
	fmt.Scan(&h, &w)

	a := make([][]int, h)
	for i := range a {
		a[i] = make([]int, w)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}

	dy := []int{0, 1}
	dx := []int{1, 0}
	isInside := func(y, x int) bool {
		return 0 <= y && y < h && 0 <= x && x < w
	}

	isUnique := func(a []int) bool {
		seen := make(map[int]bool)
		for _, ai := range a {
			if seen[ai] {
				return false
			}
			seen[ai] = true
		}
		return true
	}

	var sum int
	n := h-1 + w-1
COUNT_PATH:
	for bit := 0; bit < 1<<n; bit++ {
		var y, x int
		path := make([]int, 0, n)
		path = append(path, a[y][x])
		for i := 0; i < n; i++ {
			ny := y + dy[bit>>i&1]
			nx := x + dx[bit>>i&1]
			if !isInside(ny, nx) {
				continue COUNT_PATH
			}
			path = append(path, a[ny][nx])
			y = ny
			x = nx
		}
		if isUnique(path) {
			sum++
		}
	}

	fmt.Println(sum)
}
