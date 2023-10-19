// detail: https://atcoder.jp/contests/abc058/submissions/46735155
package main

import "fmt"

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	if b - a == c - b {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
