// detail: https://atcoder.jp/contests/abc030/submissions/39514576
package main

import "fmt"

func abs(a float64) float64 {
	if a < 0 {
		return -a
	}
	return a
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	hourHandTheta := float64(30*(n%12)) + float64(m)*0.5
	minuteHandTheta := float64(6 * m)

	fmt.Println(abs(hourHandTheta - minuteHandTheta))
}
