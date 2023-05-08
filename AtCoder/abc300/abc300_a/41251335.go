// detail: https://atcoder.jp/contests/abc300/submissions/41251335
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	defer stdout.Flush()

	var n, a, b int
	fmt.Fscan(stdin, &n, &a, &b)

	c := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(stdin, &c[i])
	}

	for i, v := range c {
		if v == a+b {
			fmt.Println(i + 1)
			break
		}
	}
}
