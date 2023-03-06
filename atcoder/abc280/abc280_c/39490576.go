// detail: https://atcoder.jp/contests/abc280/submissions/39490576
package main

import "fmt"

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	for i := range s {
		if s[i] != t[i] {
			fmt.Println(i + 1)
			break
		}
	}
}
