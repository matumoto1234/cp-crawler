// detail: https://atcoder.jp/contests/caddi2018b/submissions/39971788
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(stdin, &n)

	a := make([]int, n)
	for i := range a {
		fmt.Fscan(stdin, &a[i])
	}

	for _, ai := range a {
		if ai%2 == 1 {
			fmt.Println("first")
			return
		}
	}
	fmt.Println("second")
}
