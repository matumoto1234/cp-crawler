// detail: https://atcoder.jp/contests/abc023/submissions/40313492
package main

import "fmt"

func main() {
	var x int
	fmt.Scan(&x)

	sum := x % 10
	x /= 10
	sum += x % 10

	fmt.Println(sum)
}
