// detail: https://atcoder.jp/contests/abc148/submissions/46736077
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	current := 1
	eraseCount := 0
	for _, v := range a {
		if current == v {
			current++
		} else {
			eraseCount++
		}
	}

	if current == 1 { // not found
		eraseCount = -1
	}

	fmt.Println(eraseCount)
}
