// detail: https://atcoder.jp/contests/abc116/submissions/30561544
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MAX_N = 100

func chmax(ptr_a *int, b int) bool {
	a := *ptr_a
	if a >= b {
		return false
	}
	*ptr_a = b
	return true
}

func max_valid_interval(n int, hs [MAX_N]int) [2]int {
	cnt := 0
	max_cnt := -1
	end_idx := -1

	for i := 0; i < n; i++ {
		if hs[i] == 0 {
			cnt = 0
		}

		if hs[i] >= 1 {
			cnt++
		}

		updated := chmax(&max_cnt, cnt)
		if updated {
			end_idx = i
		}
	}

	begin_idx := end_idx - max_cnt + 1

	return [2]int{begin_idx, end_idx}
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	defer stdout.Flush()

	var n int
	fmt.Fscan(stdin, &n)

	var hs [MAX_N]int
	for i := 0; i < n; i++ {
		fmt.Fscan(stdin, &hs[i])
	}

	ans := 0

	for {
		interval := max_valid_interval(n, hs)
		begin := interval[0]
		end := interval[1]
		// fmt.Println(hs[0:n], begin, end)

		if begin > end {
			break
		}

		for i := begin; i <= end; i++ {
			hs[i]--
		}

		ans++
	}

	fmt.Fprintln(stdout, ans)
}
