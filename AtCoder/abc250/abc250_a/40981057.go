// detail: https://atcoder.jp/contests/abc250/submissions/40981057
package main

import "fmt"

func main() {
	var h, w int
	fmt.Scan(&h, &w)

	var r, c int
	fmt.Scan(&r, &c)

	r--
	c--

	dy := []int{0, 1, 0, -1}
	dx := []int{1, 0, -1, 0}

	ans := 0

	for i := 0; i < 4; i++ {
		ny := r + dy[i]
		nx := c + dx[i]
		if ny < 0 || ny >= h || nx < 0 || nx >= w {
			continue
		}
		ans++
	}

	fmt.Println(ans)
}
