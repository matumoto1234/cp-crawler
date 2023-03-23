// detail: https://atcoder.jp/contests/abc252/submissions/39969934
package main

import "fmt"

func max(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	b := make([]int, k)
	for i := range b {
		fmt.Scan(&b[i])
	}

	maxElement := max(a)

	for _, bi := range b {
		bi--
		if a[bi] == maxElement {
			fmt.Println("Yes")
			return
		}
	}

	fmt.Println("No")
}
