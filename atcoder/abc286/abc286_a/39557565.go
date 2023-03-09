// detail: https://atcoder.jp/contests/abc286/submissions/39557565
package main

import "fmt"

func main() {
	var n, p, q, r, s int
	fmt.Scan(&n, &p, &q, &r, &s)

	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	p--
	q--
	r--
	s--

	ans := make([]int, 0, n)
	ans = append(ans, a[:p]...)
	ans = append(ans, a[r:s+1]...)
	ans = append(ans, a[q+1:r]...)
	ans = append(ans, a[p:q+1]...)
	ans = append(ans, a[s+1:]...)

	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(ans[i])
	}
	fmt.Println()
}
