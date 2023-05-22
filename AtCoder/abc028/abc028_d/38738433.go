// detail: https://atcoder.jp/contests/abc028/submissions/38738433
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	defer stdout.Flush()

	var n, k int64
	fmt.Fscan(stdin, &n, &k)

	all := n * n * n
	cnt := k*(n-k+1)*6 - ((k - 1) * 3) - ((n - k) * 3) - 5
	fmt.Println(float64(cnt) / float64(all))
}
