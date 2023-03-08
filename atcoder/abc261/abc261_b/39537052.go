// detail: https://atcoder.jp/contests/abc261/submissions/39537052
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]string, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	// b[i][j] :=  {1 : win | 0 : draw | -1 : lose}
	b := make([][]int, n)
	for i := 0; i < n; i++ {
		b[i] = make([]int, n)
		for j := 0; j < n; j++ {
			switch a[i][j] {
			case 'W':
				b[i][j] = 1
			case 'D':
				b[i][j] = 0
			case 'L':
				b[i][j] = -1
			}
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}

			if b[i][j] != -b[j][i] {
				fmt.Println("incorrect")
				return
			}
		}
	}
	fmt.Println("correct")
}
