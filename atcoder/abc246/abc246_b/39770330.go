// detail: https://atcoder.jp/contests/abc246/submissions/39770330
package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b float64
	fmt.Scan(&a, &b)

	radian := math.Atan2(b, a)
	fmt.Println(math.Cos(radian), math.Sin(radian))
}
