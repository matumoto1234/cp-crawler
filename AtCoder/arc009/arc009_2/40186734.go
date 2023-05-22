// detail: https://atcoder.jp/contests/arc009/submissions/40186734
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	defer stdout.Flush()

	b := make([]int, 10)
	for i := 0; i < len(b); i++ {
		fmt.Fscan(stdin, &b[i])
	}

	valToBIndex := make(map[int]int) // 1-indexed
	for i, v := range b {
		valToBIndex[v] = i + 1
	}

	toBString := func(x int) string {
		s := ""
		for ; x > 0; x /= 10 {
			i := valToBIndex[x%10]
			if i == 10 {
				s = s + "A"
			} else {
				s = s + fmt.Sprint(i)
			}
		}
		return s
	}

	less := func(x, y int) bool {
		xStr := toBString(x)
		yStr := toBString(y)

		x2, _ := strconv.ParseInt(xStr, 16, 64)
		y2, _ := strconv.ParseInt(yStr, 16, 64)

		return x2 < y2
	}

	var n int
	fmt.Fscan(stdin, &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(stdin, &a[i])
	}

	sort.Slice(a, func(i, j int) bool {
		return less(a[i], a[j])
	})

	for _, v := range a {
		fmt.Fprintln(stdout, v)
	}
}
