// detail: https://atcoder.jp/contests/abc172/submissions/39939456
package main

import "fmt"

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	count := 0
	for i := 0; i < len(s); i++ {
		if s[i] != t[i] {
			count++
		}
	}

	fmt.Println(count)
}
