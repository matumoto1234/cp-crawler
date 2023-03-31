// detail: https://atcoder.jp/contests/abc291/submissions/40185563
package main

import (
	"fmt"
	"unicode"
)

func main() {
	var s string
	fmt.Scan(&s)

	for i := 0; i < len(s); i++ {
		if unicode.IsUpper(rune(s[i])) {
			fmt.Println(i + 1)
			break
		}
	}
}
