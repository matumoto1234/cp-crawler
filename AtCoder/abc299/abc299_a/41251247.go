// detail: https://atcoder.jp/contests/abc299/submissions/41251247
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	var s string
	fmt.Scan(&s)

	begin := 0
	for i := 0; i < n; i++ {
		if s[i] == '|' {
			begin = i
			break
		}
	}

	end := 0
	for i := 0; i < n; i++ {
		if s[i] == '|' && i != begin {
			end = i
			break
		}
	}

	star := 0
	for i := 0; i < n; i++ {
		if s[i] == '*' {
			star = i
			break
		}
	}

	if begin < star && star < end {
		fmt.Println("in")
	} else {
		fmt.Println("out")
	}
}
