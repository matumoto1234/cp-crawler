// detail: https://atcoder.jp/contests/abc033/submissions/39514061
package main

import "fmt"

func isSame(n string) bool {
	used := make(map[rune]bool)
	used[rune(n[0])] = true
	for _, digit := range n {
		if !used[digit] {
			return false
		}
	}
	return true
}

func main() {
	var n string
	fmt.Scan(&n)

	if isSame(n) {
		fmt.Println("SAME")
	} else {
		fmt.Println("DIFFERENT")
	}
}
