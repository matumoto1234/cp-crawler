// detail: https://atcoder.jp/contests/abc255/submissions/38756562
package main

import (
	"bufio"
	"os"
	"fmt"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	stderr := bufio.NewWriter(os.Stderr)
	defer stdout.Flush()
	defer stderr.Flush()

	var r, c int
	fmt.Fscan(stdin, &r, &c)
	r--
	c--

	a := make([][]int, 2)
	for i := 0; i < 2; i++ {
		a[i] = make([]int, 2)
		for j := 0; j < 2; j++ {
			fmt.Fscan(stdin, &a[i][j])
		}
	}

	fmt.Fprintln(stdout, a[r][c])
}
