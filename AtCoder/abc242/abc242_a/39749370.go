// detail: https://atcoder.jp/contests/abc242/submissions/39749370
package main

import "fmt"

func main() {
	var a, b, c, x float64
	fmt.Scan(&a, &b, &c, &x)

	if x <= a {
		fmt.Println(1)
		return
	}

	if a+1 <= x && x <= b {
		fmt.Println(c/(b - a))
		return
	}

	fmt.Println(0)
}
