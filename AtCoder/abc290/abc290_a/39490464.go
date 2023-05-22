// detail: https://atcoder.jp/contests/abc290/submissions/39490464
package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	b := make([]int, m)
	for i := range b {
		fmt.Scan(&b[i])
	}

	var sum int
	for _, bi := range b {
		sum += a[bi-1]
	}

	fmt.Println(sum)
}
