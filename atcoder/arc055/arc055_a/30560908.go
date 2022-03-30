// detail: https://atcoder.jp/contests/arc055/submissions/30560908
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

	var n int

	fmt.Fscan(stdin, &n)

	fmt.Fprint(stdout, 1)

	for i := 0; i < n - 1; i++ {
		fmt.Fprint(stdout, 0)
	}

	fmt.Fprintln(stdout, 7)
}
