// detail: https://atcoder.jp/contests/abc034/submissions/39577187
package main

import "fmt"

func main() {
	var x, y int
	fmt.Scan(&x, &y)

	if x < y {
		fmt.Println("Better")
	} else {
		fmt.Println("Worse")
	}
}
