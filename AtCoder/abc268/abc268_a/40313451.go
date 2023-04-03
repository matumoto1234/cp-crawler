// detail: https://atcoder.jp/contests/abc268/submissions/40313451
package main

import "fmt"

func main() {
	var a, b, c, d, e int
	fmt.Scan(&a, &b, &c, &d, &e)

	counter := make(map[int]int)

	counter[a]++
	counter[b]++
	counter[c]++
	counter[d]++
	counter[e]++

	fmt.Println(len(counter))
}
