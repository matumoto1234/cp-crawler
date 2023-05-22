// detail: https://atcoder.jp/contests/code-festival-2015-quala/submissions/38926818
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	stderr := bufio.NewWriter(os.Stderr)
	defer stdout.Flush()
	defer stderr.Flush()

	var n, t int
	fmt.Fscan(stdin, &n, &t)

	abList := make([][2]int, n)
	for i:=0;i<n;i++ {
		fmt.Fscan(stdin, &abList[i][0], &abList[i][1])
	}

	sumA := 0
	sumB := 0
	for i:=0;i<n;i++ {
		a, b := abList[i][0], abList[i][1]
		sumA += a
		sumB += b
	}
	if sumA <= t {
		fmt.Fprintln(stdout, 0)
		return
	}
	if sumB > t {
		fmt.Fprintln(stdout, -1)
		return
	}

	// diff and index list
	diList := make([][2]int, n)
	for i:=0;i<n;i++ {
		a, b := abList[i][0], abList[i][1]
		diList[i][0] = a - b
		diList[i][1] = i
	}

	sort.Slice(diList, func(i, j int) bool {
		return diList[i][0] > diList[j][0]
	})

	sumDiff := 0
	for i:=0;i<n;i++ {
		diff := diList[i][0]
		sumDiff += diff

		if sumA - sumDiff <= t {
			fmt.Fprintln(stdout, i+1)
			return
		}
	}
}
