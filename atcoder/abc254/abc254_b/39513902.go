// detail: https://atcoder.jp/contests/abc254/submissions/39513902
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	a := make([][]int, n+1)
	for i := 1; i <= n; i++ {
		a[i] = make([]int, i+1)
	}

	for i := 1; i <= n; i++ {
		for j := 0; j < i; j++ {
			if j == 0 {
				a[i][j] = 1
				continue
			}
			if j == i-1 {
				a[i][j] = 1
				continue
			}
			a[i][j] = a[i-1][j-1] + a[i-1][j]
		}
	}

	for i := 1; i <= n; i++ {
		for j := 0; j < i; j++ {
			if j > 0 {
				fmt.Print(" ")
			}
			fmt.Print(a[i][j])
		}
		fmt.Println()
	}
}
