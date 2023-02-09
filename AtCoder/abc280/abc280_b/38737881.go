// detail: https://atcoder.jp/contests/abc280/submissions/38737881
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

	var n int64
	fmt.Fscan(r, &n)

	s := make([]int64, n)
	for i := int64(0); i < n; i++ {
		fmt.Fscan(r, &s[i])
	}

	a := make([]int64, n)
	for i := int64(0); i < n; i++ {
		if i == 0 {
			a[i] = s[i]
			continue
		}
		a[i] = s[i] - s[i-1]
	}

	for i, v := range a {
		fmt.Fprint(w, v)

		if int64(i) != n-1 {
			fmt.Fprint(w, " ")
		}
	}

	fmt.Fprintln(w)
}
