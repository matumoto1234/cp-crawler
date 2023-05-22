// detail: https://atcoder.jp/contests/abc198/submissions/39136426
package main

import "fmt"

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	var r, x, y int
	fmt.Scan(&r, &x, &y)

	d := x*x + y*y
	if d < r*r {
		fmt.Println(2)
		return
	}

	INF := 100000
	valid := INF
	invalid := 0

	isValid := func(mid int) bool {
		return uint64(mid*mid)*uint64(r*r) >= uint64(d)
	}

	for abs(valid-invalid) > 1 {
		mid := (valid + invalid) / 2
		if isValid(mid) {
			valid = mid
		} else {
			invalid = mid
		}
	}

	fmt.Println(valid)
}
