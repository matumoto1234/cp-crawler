// detail: https://atcoder.jp/contests/abc225/submissions/39156001
package main

import "fmt"

func main() {
	var s string
	fmt.Scan(&s)

	counter := make(map[rune]int, 0)
	for _, r := range s {
		counter[r]++
	}

	if len(counter) == 1 {
		fmt.Println(1)
	} else if len(counter) == 2 {
		fmt.Println(3 * 2 / 2)
	} else {
		fmt.Println(3 * 2)
	}
}
