// detail: https://atcoder.jp/contests/abc252/submissions/39577579
package main

import "fmt"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func maxElementIndex(a []int) int {
	maxIndex := 0
	maxElem := a[maxIndex]
	for i, ai := range a {
		if maxElem <= ai {
			maxIndex = i
			maxElem = ai
		}
	}
	return maxIndex
}

func main() {
	var n int
	fmt.Scan(&n)

	s := make([]string, n)
	for i := range s {
		fmt.Scan(&s[i])
	}

	const INF = 1 << 30
	ans := INF
	for target := '0'; target <= '9'; target++ {
		targetCounter := make([]int, 10)
		for _, si := range s {
			for i, ch := range si {
				if ch == target {
					targetCounter[i]++
				}
			}
		}

		idx := maxElementIndex(targetCounter)
		ans = min(ans, (targetCounter[idx]-1)*10+idx)
	}
	fmt.Println(ans)
}
