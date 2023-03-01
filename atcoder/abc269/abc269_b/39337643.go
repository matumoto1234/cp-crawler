// detail: https://atcoder.jp/contests/abc269/submissions/39337643
package main

import "fmt"

func main() {
	s := make([]string, 10)
	for i := range s {
		fmt.Scan(&s[i])
	}

	leftUp := [2]int{0, 0}

FIND_LEFTUP:
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			if s[i][j] == '#' {
				leftUp = [2]int{i, j}
				break FIND_LEFTUP
			}
		}
	}

	rightDown := [2]int{9, 9}

FIND_RIGHTDOWN:
	for i := 9; i >= 0; i-- {
		for j := 9; j >= 0; j-- {
			if s[i][j] == '#' {
				rightDown = [2]int{i, j}
				break FIND_RIGHTDOWN
			}
		}
	}

	y1, x1 := leftUp[0], leftUp[1]
	y2, x2 := rightDown[0], rightDown[1]

	a := y1 + 1
	b := y2 + 1
	c := x1 + 1
	d := x2 + 1
	fmt.Println(a, b)
	fmt.Println(c, d)
}
