// detail: https://atcoder.jp/contests/arc147/submissions/38946331
package main

import (
	"bufio"
	"fmt"
	"os"
)

func swap(x, y *int) {
	*x, *y = *y, *x
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	defer stdout.Flush()

	var n int
	fmt.Fscan(stdin, &n)

	p := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(stdin, &p[i])
	}

	ans := make([]string, 0, 100000)

	for i := 0; i < n; i++ {
		now := i
		dist := abs(p[i] - (i + 1))
		if dist%2 == 0 {
			continue
		}

		for {
			next := now + 1
			distNext := abs(p[next] - (next + 1))

			if distNext%2 == 1 {
				swap(&p[now], &p[next])
				ans = append(ans, fmt.Sprintf("A %d", now+1))
				now++
				break
			}

			swap(&p[now], &p[now+2])
			ans = append(ans, fmt.Sprintf("B %d", now+1))
			now += 2
		}
	}

	// t := target
	for t := 1; t <= n; t++ {
		// target index
		ti := -1
		for i := 0; i < n; i++ {
			if t == p[i] {
				ti = i
				break
			}
		}

		// destination index
		dest := t - 1
		for ti != dest {
			if ti < dest {
				swap(&p[ti], &p[ti+2])
				ans = append(ans, fmt.Sprintf("B %d", ti+1))
				ti += 2
			} else {
				swap(&p[ti], &p[ti-2])
				ans = append(ans, fmt.Sprintf("B %d", ti-2+1))
				ti -= 2
			}
		}
	}

	fmt.Fprintln(stdout, len(ans))
	for _, s := range ans {
		fmt.Fprintln(stdout, s)
	}
}
