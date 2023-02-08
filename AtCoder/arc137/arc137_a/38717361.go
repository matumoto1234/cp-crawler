// detail: https://atcoder.jp/contests/arc137/submissions/38717361
package main

import (
	"bufio"
	"fmt"
	"os"
)

func gcd64(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func max64(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var l, r int64
	fmt.Fscan(stdin, &l, &r)

	ans := int64(-1)

	for x := l; x <= l+1000; x++ {
		for y := r; y >= r-1000; y-- {
			if x < y && gcd64(x, y) == 1{
				ans = max64(ans, y - x)
			}
		}
	}

	fmt.Println(ans)
}
