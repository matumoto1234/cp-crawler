// detail: https://atcoder.jp/contests/exawizards2019/submissions/30560737
package main

import (
	"fmt"
	"bufio"
	"os"
)

func main() {
    stdin := bufio.NewReader(os.Stdin)
    stdout := bufio.NewWriter(os.Stdout)
    defer stdout.Flush()

    var a, b, c int

    fmt.Fscan(stdin, &a, &b, &c)

		ans := a == b && b == c && a == c

		if ans {
			fmt.Fprintln(stdout, "Yes")
		} else {
			fmt.Fprintln(stdout, "No")
		}
}
