// detail: https://atcoder.jp/contests/agc026/submissions/39791555
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	count := 0
	for i:=0;i<n-1;i++ {
		if a[i] == a[i+1] {
			count++
			i++
		}
	}

	fmt.Println(count)
}
