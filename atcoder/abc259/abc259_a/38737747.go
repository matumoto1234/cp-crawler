// detail: https://atcoder.jp/contests/abc259/submissions/38737747
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    r := bufio.NewReader(os.Stdin)
    w := bufio.NewWriter(os.Stdout)
    defer w.Flush()

	var n, m, x, t, d int
	fmt.Fscan(r, &n, &m, &x, &t, &d)

	bias := t - (x * d)

	if m >= x {
		fmt.Println(bias + x * d)
	} else {
		fmt.Println(bias + m * d)
	}
}
