// detail: https://atcoder.jp/contests/arc137/submissions/38927472
package main

import (
	"bufio"
	"fmt"
	"os"
)

func runLengthCompression(a []int) [][2]int {
	// compressed
	var c [][2]int
	for _, ai := range a {
		if len(c) == 0 || c[len(c)-1][0] != ai {
			c = append(c, [2]int{ai, 0})
		}
		// back count++
		c[len(c)-1][1]++
	}
	return c
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
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

	c := runLengthCompression(a)

	var maxContinuousCount int

	for i := 0; i < len(c)-1; i++ {
		// current
		cnt1 := c[i][1]

		// next
		cnt2 := c[i+1][1]

		maxContinuousCount = max(maxContinuousCount, cnt1+cnt2)
	}
	if len(c) == 1 {
		maxContinuousCount = c[0][1]
	}

	fmt.Println(maxContinuousCount+1)
}
