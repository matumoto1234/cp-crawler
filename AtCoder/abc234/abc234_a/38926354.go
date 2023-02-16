// detail: https://atcoder.jp/contests/abc234/submissions/38926354
package main

import (
	"bufio"
	"fmt"
	"os"
)

func f(x int) int {
	return x*x + 2*x + 3
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	stderr := bufio.NewWriter(os.Stderr)
	defer stdout.Flush()
	defer stderr.Flush()

	var t int
	fmt.Fscan(stdin, &t)

	fmt.Println(f(f(f(t) + t) + f(f(t))))
}
