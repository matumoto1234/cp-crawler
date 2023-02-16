// detail: https://atcoder.jp/contests/arc137/submissions/38929937
package main

import (
	"bufio"
	"fmt"
	"os"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func convert(a []int) []int {
	res := make([]int, len(a))
	for i, ai := range a {
		if ai == 0 {
			res[i] = -1
		} else {
			res[i] = 1
		}
	}
	return res
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	stderr := bufio.NewWriter(os.Stderr)
	defer stdout.Flush()
	defer stderr.Flush()

	var n int
	fmt.Fscan(stdin, &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(stdin, &a[i])
	}

	// converted
	c := convert(a)

	// cumulative sum
	s := make([]int, n+1)
	for i:=0;i<n;i++ {
		s[i+1] = s[i] + c[i]
	}

	INF := 1 << 60

	maxS := -INF
	minS := INF
	maxLeft := 0
	for i:=1;i<n+1;i++ {
		maxS = max(maxS, s[i] - maxLeft)
		minS = min(minS, s[i] - maxLeft)
		maxLeft = max(maxLeft, s[i])
	}
	fmt.Println(maxS - minS + 1 + 1)
}
