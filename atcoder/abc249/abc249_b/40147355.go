// detail: https://atcoder.jp/contests/abc249/submissions/40147355
package main

import (
	"fmt"
	"sort"
)

func existsUpper(s string) bool {
	for _, ch := range s {
		if ch >= 'A' && ch <= 'Z' {
			return true
		}
	}
	return false
}

func existsLower(s string) bool {
	for _, ch := range s {
		if ch >= 'a' && ch <= 'z' {
			return true
		}
	}
	return false
}

func isDifferentChars(s string) bool {
	r := []rune(s)

	sort.Slice(r, func(i, j int) bool {
		return r[i] < r[j]
	})

	for i := 0; i < len(r)-1; i++ {
		if r[i] == r[i+1] {
			return false
		}
	}

	return true
}

func main() {
	var s string
	fmt.Scan(&s)

	if existsLower(s) && existsUpper(s) && isDifferentChars(s) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
