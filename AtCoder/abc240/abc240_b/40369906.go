// detail: https://atcoder.jp/contests/abc240/submissions/40369906
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	counter := make(map[int]int)
	for _, v := range a {
		counter[v]++
	}

	fmt.Println(len(counter))
}
