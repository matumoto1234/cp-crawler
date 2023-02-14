// detail: https://atcoder.jp/contests/abc234/submissions/38887615
package main

import (
	"fmt"
	"math"
)

func dist(x1, y1, x2, y2 int) float64 {
	return math.Sqrt(float64((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)))
}

func max(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n int
	fmt.Scan(&n)

	xyList := make([][2]int, n)
	for i:=0;i<n;i++ {
		fmt.Scan(&xyList[i][0], &xyList[i][1])
	}

	var ans float64
	for _, xy1 := range xyList {
		for _, xy2 := range xyList {
			d := dist(xy1[0], xy1[1], xy2[0], xy2[1])
			ans = max(ans, d)
		}
	}
	fmt.Println(ans)
}
