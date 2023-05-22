// detail: https://atcoder.jp/contests/abc280/submissions/39490634
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)

	var s, t string
	fmt.Fscan(stdin, &s, &t)

	for i := range s {
		if s[i] != t[i] {
			fmt.Println(i + 1)
			return
		}
	}
	fmt.Println(len(t))
}
