// detail: https://atcoder.jp/contests/arc142/submissions/39749943
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	stdout := bufio.NewWriter(os.Stdout)
	defer stdout.Flush()

	var n int
	fmt.Scan(&n)

	ans := make([][]int, n)
	for i := 0; i < n; i++ {
		ans[i] = make([]int, n)
	}

	dy := []int{0, 1, 0, -1}
	dx := []int{1, 0, -1, 0}

	y, x := 0, 0
	dir := 0

	isInside := func(y, x int) bool {
		return 0 <= y && y < n && 0 <= x && x < n
	}

	for i := 0; i < n*n; i++ {
		ans[y][x] = i + 1
		ny, nx := y+dy[dir], x+dx[dir]
		if !isInside(ny, nx) || ans[ny][nx] != 0 {
			dir++
			dir %= 4
			ny, nx = y+dy[dir], x+dx[dir]
		}
		y, x = ny, nx
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if j > 0 {
				fmt.Fprint(stdout, " ")
			}
			fmt.Fprint(stdout, ans[i][j])
		}
		fmt.Fprintln(stdout)
	}
}
