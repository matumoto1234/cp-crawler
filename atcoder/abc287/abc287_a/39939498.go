// detail: https://atcoder.jp/contests/abc287/submissions/39939498
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	forCount := 0

	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)

		if s == "For" {
			forCount++
		}
	}

	if forCount >= (n+1)/2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
