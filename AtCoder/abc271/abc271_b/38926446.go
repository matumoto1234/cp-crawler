// detail: https://atcoder.jp/contests/abc271/submissions/38926446
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	stderr := bufio.NewWriter(os.Stderr)
	defer stdout.Flush()
	defer stderr.Flush()

	var n, q int
	fmt.Fscan(stdin, &n, &q)

	a := make([][]int, n)
	for i:=0;i<n;i++ {
		var li int
		fmt.Fscan(stdin, &li)

		a[i] = make([]int, li)
		for j:=0;j<li;j++ {
			fmt.Fscan(stdin, &a[i][j])
		}
	}

	for i:=0;i<q;i++ {
		var s, t int
		fmt.Fscan(stdin, &s, &t)

		s--
		t--

		fmt.Fprintln(stdout, a[s][t])
	}
}
