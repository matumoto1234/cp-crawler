// detail: https://atcoder.jp/contests/abc289/submissions/38803607
package main

import (
	"fmt"
)

func exists(a []int64, x int64) bool {
	for _, n := range a {
		if x == n {
			return true
		}
	}
	return false
}

func pow64(x, y int64) int64 {
	var ans int64 = 1
	for i := int64(0); i < y; i++ {
		ans *= x
	}
	return ans
}

func main() {
	var n, m int64
	fmt.Scan(&n, &m)

	c := make([]int64, m)
	a := make([][]int64, m)
	for i := int64(0); i < m; i++ {
		fmt.Scan(&c[i])

		a[i] = make([]int64, c[i])
		for j := int64(0); j < c[i]; j++ {
			fmt.Scan(&a[i][j])
		}
	}

	var ans int64

BitSearch:
	for bit := int64(1); bit < pow64(2, m); bit++ {
		selectedList := make([]int64, 0)
		for i := int64(0); i < m; i++ {
			if (bit>>i)&1 == 1 {
				selectedList = append(selectedList, a[i]...)
			}
		}
		for x := int64(1); x <= n; x++ {
			if !exists(selectedList, x) {
				continue BitSearch
			}
		}

		ans++
	}

	fmt.Println(ans)
}
