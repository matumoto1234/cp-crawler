// detail: https://atcoder.jp/contests/arc137/submissions/38930513
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

func min(a, b int) int {
	if a < b {
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

	default1Count := 0
	for i := 0; i < n; i++ {
		default1Count += a[i]
	}

	min1Count := default1Count
	max1Count := default1Count

	for i := range c {
		// current count
		cur := c[i][1]

		if c[i][0] == 0 {
			max1Count = max(max1Count, default1Count+cur)
		}

		if c[i][0] == 1 {
			min1Count = min(min1Count, default1Count-cur)
		}
	}

	fmt.Println(max1Count - min1Count + 1)
}
