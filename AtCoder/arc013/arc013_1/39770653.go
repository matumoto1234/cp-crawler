// detail: https://atcoder.jp/contests/arc013/submissions/39770653
package main

import "fmt"

func max(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func main() {
	var n, m, l int
	fmt.Scan(&n, &m, &l)

	var p, q, r int
	fmt.Scan(&p, &q, &r)

	packingCount := func(a, b, c int) int {
		return (n / a) * (m / b) * (l / c)
	}

	neutral := packingCount(p, q, r)
	leftRotate := packingCount(q, p, r)
	rightRotate := packingCount(q, p, r)
	upRotate := packingCount(r, q, p)
	downRotate := packingCount(r, q, p)
	fmt.Println(max([]int{neutral, leftRotate, rightRotate, upRotate, downRotate}))
}
