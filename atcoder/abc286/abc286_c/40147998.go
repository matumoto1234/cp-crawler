// detail: https://atcoder.jp/contests/abc286/submissions/40147998
package main

import (
	"bufio"
	"fmt"
	"os"
)

func diffToPalindrome(s string) int {
	var cost int
	for i := 0; i < len(s)/2; i++ {
		j := len(s) - 1 - i
		if s[i] != s[j] {
			cost++
		}
	}
	return cost
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	stdin := bufio.NewReader(os.Stdin)

	var n, a, b int
	var s string
	fmt.Fscan(stdin, &n, &a, &b, &s)

	const INF = 1 << 60
	ans := INF

	for i := 0; i < n; i++ {
		diff := diffToPalindrome(s)
		ans = min(ans, diff * b + i * a)
		s = s[1:] + string(s[0])
	}

	fmt.Println(ans)
}
