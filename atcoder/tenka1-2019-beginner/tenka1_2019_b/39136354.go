// detail: https://atcoder.jp/contests/tenka1-2019-beginner/submissions/39136354
package main

import "fmt"

func main() {
	var n int
	var s string
	var k int

	fmt.Scan(&n, &s, &k)

	ans := ""
	for i := range s {
		if s[i] != s[k-1] {
			ans += "*"
		} else {
			ans += string(s[i])
		}
	}

	fmt.Println(ans)
}
