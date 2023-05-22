// detail: https://atcoder.jp/contests/arc020/submissions/40369975
package main

import "fmt"

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	if abs(a) < abs(b) {
		fmt.Println("Ant")
	} else if abs(a) == abs(b) {
		fmt.Println("Draw")
	} else {
		fmt.Println("Bug")
	}
}
