// detail: https://atcoder.jp/contests/agc031/submissions/39158071
package main

import "fmt"

func main() {
	var s string
	fmt.Scan(&s)

	counter := make(map[rune]int, 0)
	for _, c := range s {
		counter[c]++
	}

	mod := 1000000007
	ans := 1
	for _, cnt := range counter {
		ans *= cnt + 1
		ans %= mod
	}

	fmt.Println(ans - 1)
}
