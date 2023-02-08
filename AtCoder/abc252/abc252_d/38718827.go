// detail: https://atcoder.jp/contests/abc252/submissions/38718827
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

	var n int64
	fmt.Fscan(stdin, &n)

	a := make([]int64, n)
	for i := int64(0); i < n; i++ {
		fmt.Fscan(stdin, &a[i])
	}

	counter := make(map[int64]int64)
	for _, ai := range a {
		counter[ai]++
	}

	var ans int64
	ans = n * (n - 1) * (n - 2) / 6
	for _, c := range counter {
		if c == 2 {
			comb := c * (c - 1) / 2
			ans -= comb * (n - c)
		}
		if c >= 3 {
			comb := c * (c - 1) * (c - 2) / 6
			ans -= comb
		}
	}

	fmt.Fprintln(stdout, ans)
}
