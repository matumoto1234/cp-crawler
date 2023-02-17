// detail: https://atcoder.jp/contests/abc010/submissions/38945219
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func dist(x1, y1, x2, y2 int) float64 {
	return math.Sqrt(float64((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)))
}

func main() {
	stdin := bufio.NewReader(os.Stdin)

	var txa, tya, txb, tyb, t, v int
	fmt.Fscan(stdin, &txa, &tya, &txb, &tyb, &t, &v)

	var n int
	fmt.Fscan(stdin, &n)

	xyList := make([][2]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(stdin, &xyList[i][0], &xyList[i][1])
	}

	for i := 0; i < n; i++ {
		x, y := xyList[i][0], xyList[i][1]

		d1 := dist(txa, tya, x, y)
		d2 := dist(x, y, txb, tyb)

		if d1+d2 <= float64(t*v) {
			fmt.Println("YES")
			return
		}
	}

	fmt.Println("NO")
}
