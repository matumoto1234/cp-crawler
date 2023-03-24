// detail: https://atcoder.jp/contests/abc243/submissions/39990731
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	b := make([]int, n)
	for i := range b {
		fmt.Scan(&b[i])
	}

	var count1, count2 int

	aCounter := make(map[int]int)
	for _, ai := range a {
		aCounter[ai]++
	}

	for i := 0; i < n; i++ {
		if a[i] == b[i] {
			count1++
		}

		if a[i] != b[i] {
			count2 += aCounter[b[i]]
		}
	}

	fmt.Println(count1)
	fmt.Println(count2)
}
