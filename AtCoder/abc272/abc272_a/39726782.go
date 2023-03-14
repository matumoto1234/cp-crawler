// detail: https://atcoder.jp/contests/abc272/submissions/39726782
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	sum := 0
	for _, ai := range a {
		sum += ai
	}

	fmt.Println(sum)
}
