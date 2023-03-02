// detail: https://atcoder.jp/contests/abc291/submissions/39356827
package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	x := make([]int, 5*n)
	for i := range x {
		fmt.Scan(&x[i])
	}

	sort.Slice(x, func(i, j int) bool {
		return x[i] < x[j]
	})

	sum := 0
	for i := n; i < 4*n; i++ {
		sum += x[i]
	}

	fmt.Println(float64(sum) / float64(3*n))
}
