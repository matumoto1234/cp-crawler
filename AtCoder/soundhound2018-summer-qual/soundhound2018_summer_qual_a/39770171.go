// detail: https://atcoder.jp/contests/soundhound2018-summer-qual/submissions/39770171
package main

import "fmt"

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	if a+b == 15 {
		fmt.Println("+")
		return
	}

	if a*b == 15 {
		fmt.Println("*")
		return
	}

	fmt.Println("x")
}
