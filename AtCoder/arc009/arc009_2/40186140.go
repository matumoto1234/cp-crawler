// detail: https://atcoder.jp/contests/arc009/submissions/40186140
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
	defer stdout.Flush()

	b := make([]int64, 10)
	for i := 0; i < len(b); i++ {
		fmt.Fscan(stdin, &b[i])
	}

	valToBIndex := make(map[int64]int)
	for i, v := range b {
		valToBIndex[v] = i
	}

	toBString := func(x int64) string {
		s := ""
		for ; x > 0; x /= 10 {
			i := valToBIndex[x%10]
			s = s + fmt.Sprint(i)
		}
		return s
	}

	less := func(x, y int64) bool {
		xStr := toBString(x)
		yStr := toBString(y)

		if len(xStr) == len(yStr) {
			return xStr < yStr
		}

		return len(xStr) < len(yStr)
	}

	var n int64
	fmt.Fscan(stdin, &n)

	a := make([]int64, n)
	for i := int64(0); i < n; i++ {
		fmt.Fscan(stdin, &a[i])
	}

	sort.Slice(a, func(i, j int) bool {
		return less(a[i], a[j])
	})

	for _, v := range a {
		fmt.Fprintln(stdout, v)
	}
}
