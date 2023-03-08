// detail: https://atcoder.jp/contests/abc235/submissions/39536735
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var s string
	fmt.Scan(&s)

	a, _ := strconv.ParseInt(string(s[0]), 10, 64)
	b, _ := strconv.ParseInt(string(s[1]), 10, 64)
	c, _ := strconv.ParseInt(string(s[2]), 10, 64)

	v1 := a*100 + b*10 + c
	v2 := b*100 + c*10 + a
	v3 := c*100 + a*10 + b
	fmt.Println(v1 + v2 + v3)
}
