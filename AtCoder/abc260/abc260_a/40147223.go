// detail: https://atcoder.jp/contests/abc260/submissions/40147223
package main

import "fmt"

func main() {
	var s string
	fmt.Scan(&s)

	counter := make(map[byte]int)

	for _, ch := range s {
		counter[byte(ch)]++
	}

	for ch, count := range counter {
		if count == 1 {
			fmt.Println(string(ch))
			return
		}
	}

	fmt.Println(-1)
}
