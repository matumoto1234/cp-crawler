// detail: https://atcoder.jp/contests/arc008/submissions/38757099
package main

import (
	"bufio"
	"fmt"
	"os"
)

func characterCounter(s string) map[rune]int64 {
	counter := make(map[rune]int64)
	for _, c := range s {
		counter[c]++
	}
	return counter
}

func ceil64(a, b int64) int64 {
	return (a + b - 1) / b
}

func max64(a, b int64) int64 {
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

	var n, m int
	fmt.Fscan(stdin, &n, &m)

	var name string
	fmt.Fscan(stdin, &name)

	var kit string
	fmt.Fscan(stdin, &kit)

	nameCounter := characterCounter(name)
	kitCounter := characterCounter(kit)

	var max int64

	for c, count := range nameCounter {
		kitCount, ok := kitCounter[c]
		if !ok {
			fmt.Println(-1)
			return
		}

		max = max64(max, ceil64(count, kitCount))
	}

	fmt.Println(max)
}
