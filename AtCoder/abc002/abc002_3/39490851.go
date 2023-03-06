// detail: https://atcoder.jp/contests/abc002/submissions/39490851
package main

import (
	"fmt"
	"math"
)

func heronFormula(a, b, c float64) float64 {
	s := (a + b + c) / 2
	return math.Sqrt(s * (s - a) * (s - b) * (s - c))
}

func euclidDist(x1, y1, x2, y2 int) float64 {
	return math.Sqrt(float64((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)))
}

func main() {
	var xa, ya, xb, yb, xc, yc int
	fmt.Scan(&xa, &ya, &xb, &yb, &xc, &yc)

	ab := euclidDist(xa, ya, xb, yb)
	ac := euclidDist(xa, ya, xc, yc)
	bc := euclidDist(xb, yb, xc, yc)
	fmt.Println(heronFormula(ab, ac, bc))
}
