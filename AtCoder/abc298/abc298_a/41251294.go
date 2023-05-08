// detail: https://atcoder.jp/contests/abc298/submissions/41251294
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	var s string
	fmt.Scan(&s)

	existsGood := false
	for i := 0; i < n; i++ {
		if s[i] == 'o' {
			existsGood = true
			break
		}
	}

	existsBad := false
	for i := 0; i < n; i++ {
		if s[i] == 'x' {
			existsBad = true
			break
		}
	}

	if existsGood && !existsBad {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
