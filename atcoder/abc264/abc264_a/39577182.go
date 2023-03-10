// detail: https://atcoder.jp/contests/abc264/submissions/39577182
package main

import "fmt"

func main() {
	var l, r int
	fmt.Scan(&l, &r)

	l--
	r--
	atcoder := "atcoder"
	fmt.Println(atcoder[l : r+1])
}
