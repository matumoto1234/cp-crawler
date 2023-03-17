// detail: https://atcoder.jp/contests/abc293/submissions/39791497
package main

import "fmt"

func swap(a, b *rune) {
	*a, *b = *b, *a
}

func main() {
	var s string
	fmt.Scan(&s)

	r := []rune(s)

	for i := 0; i < len(r)/2; i++ {
		swap(&r[2*i], &r[2*i+1])
	}

	fmt.Println(string(r))
}
