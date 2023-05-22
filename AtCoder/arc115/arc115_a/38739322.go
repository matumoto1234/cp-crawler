// detail: https://atcoder.jp/contests/arc115/submissions/38739322
package main

import (
	"bufio"
	"fmt"
	"os"
)

// 1の個数
func bit1count(s string) int64 {
	count := int64(0)
	for _, v := range s {
		if v == '1' {
			count++
		}
	}
	return count
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	defer stdout.Flush()

	var n, m int64
	fmt.Fscan(stdin, &n, &m)

	s := make([]string, n)
	for i := int64(0); i < n; i++ {
		fmt.Fscan(stdin, &s[i])
	}

	odd1Count := int64(0)
	even1Count := int64(0)
	for _, v := range s {
		count := bit1count(v)
		if count%2 == 0 {
			even1Count++
		} else {
			odd1Count++
		}
	}

	fmt.Println(odd1Count * even1Count)
}
