// detail: https://atcoder.jp/contests/abc289/submissions/38792136
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

	var n, m int
	fmt.Fscan(stdin, &n, &m)

	a := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Fscan(stdin, &a[i])
	}

	flgList := make([]bool, n+2)
	for _, ai := range a {
		flgList[ai] = true
	}

	stack := make([]int, 0, n)
	ans := make([]int, 0, n)

	for i := 1; i <= n+1; i++ {
		f := flgList[i]

		if f {
			stack = append(stack, i)
			continue
		}

		if i != n+1 {

			ans = append(ans, i)
		}

		for len(stack) > 0 {
			ans = append(ans, stack[len(stack)-1])
			stack = stack[:len(stack)-1]
		}

	}

	for i, v := range ans {
		if i != 0 {
			fmt.Fprint(stdout, " ")
		}
		fmt.Fprint(stdout, v)
	}
	fmt.Fprintln(stdout)
}
