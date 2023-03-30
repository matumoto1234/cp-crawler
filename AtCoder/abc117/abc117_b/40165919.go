// detail: https://atcoder.jp/contests/abc117/submissions/40165919
package main

import "fmt"

func max(a []int) int {
	m := a[0]
	for _, v := range a {
		if m < v {
			m = v
		}
	}
	return m
}

func sum(a []int) int {
	s := 0
	for _, v := range a {
		s += v
	}
	return s
}

func main() {
	var n int
	fmt.Scan(&n)

	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	if max(l) < sum(l)-max(l) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
