// detail: https://atcoder.jp/contests/arc007/submissions/39293802
package main

import "fmt"

func main() {
	var x string
	fmt.Scan(&x)

	var s string
	fmt.Scan(&s)

	for _, c := range s {
		if c == rune(x[0]) {
			continue
		}
		fmt.Print(string(c))
	}
	fmt.Println()
}
