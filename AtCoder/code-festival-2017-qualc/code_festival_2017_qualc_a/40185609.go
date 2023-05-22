// detail: https://atcoder.jp/contests/code-festival-2017-qualc/submissions/40185609
package main

import "fmt"

func main() {
	var s string
	fmt.Scan(&s)

	for i := 0; i < len(s)-1; i++ {
		if s[i] == 'A' && s[i+1] == 'C' {
			fmt.Println("Yes")
			return
		}
	}

	fmt.Println("No")
}
