// detail: https://atcoder.jp/contests/abc278/submissions/39293678
package main

import "fmt"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	k = min(n, k)

	a = a[k:]
	for i := 0; i < k; i++ {
		a = append(a, 0)
	}

	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(a[i])
	}
	fmt.Println()
}
