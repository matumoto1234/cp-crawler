// detail: https://atcoder.jp/contests/abc292/submissions/39990877
package main

import "fmt"

func main() {
	var n, q int
	fmt.Scan(&n, &q)

	isExited := make(map[int]bool)
	yellowCount := make(map[int]int)

	for i := 0; i < q; i++ {
		var c, x int
		fmt.Scan(&c, &x)

		switch c {
		case 1:
			yellowCount[x]++
			if yellowCount[x] >= 2 {
				isExited[x] = true
			}
		case 2:
			isExited[x] = true
		case 3:
			if isExited[x] {
				fmt.Println("Yes")
			} else {
				fmt.Println("No")
			}
		}
	}
}
