// detail: https://atcoder.jp/contests/abc240/submissions/39424580
package main

import "fmt"

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	a--
	b--

	if (a+1)%10 == b || ((a-1)%10+10)%10 == b {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
