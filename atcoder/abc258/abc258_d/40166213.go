// detail: https://atcoder.jp/contests/abc258/submissions/40166213
package main

import (
	"bufio"
	"fmt"
	"os"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	stdin := bufio.NewReader(os.Stdin)

	var n, x int
	fmt.Fscan(stdin, &n, &x)

	abList := make([][2]int, n)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Fscan(stdin, &a, &b)

		abList[i][0] = a
		abList[i][1] = b
	}

	const INF = 1 << 60

	abSum := 0
	ans := INF

	for i := 0; i < n; i++ {
		a, b := abList[i][0], abList[i][1]
		abSum += a + b

		clear := i + 1 // 1-indexed

		if clear >= x {
			ans = min(ans, abSum)
			continue
		}

		cost := abSum + (x-clear)*b
		ans = min(ans, cost)
	}

	fmt.Println(ans)
}
