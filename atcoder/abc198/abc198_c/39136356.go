// detail: https://atcoder.jp/contests/abc198/submissions/39136356
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

	INF := 1 << 30
	valid := INF
	invalid := 0

	isValid := func(mid int) bool {
		return mid*mid*r*r >= d
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
