// detail: https://atcoder.jp/contests/abc289/submissions/38781038
package main

import (
	"fmt"
	"os"
	"bufio"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	defer stdout.Flush()

	var s string
	fmt.Fscan(stdin, &s)

	var ans string

	for i := 0; i < len(s); i++ {
		if s[i] == '0' {
			ans += "1"
		} else {
			ans += "0"
		}
	}

	fmt.Println(ans)
}