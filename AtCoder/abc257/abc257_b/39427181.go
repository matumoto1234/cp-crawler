// detail: https://atcoder.jp/contests/abc257/submissions/39427181
package main

import "fmt"

func main() {
	var n, k, q int
	fmt.Scan(&n, &k, &q)

	a := make([]int, k)
	for i := range a {
		fmt.Scan(&a[i])
	}

	l := make([]int, q)
	for i := range l {
		fmt.Scan(&l[i])
	}

	spaceList := make([]bool, n+1)
	for _, ai := range a {
		spaceList[ai] = true
	}

	for _, li := range l {
		idx := li - 1
		if a[idx] == n {
			continue
		}
		if spaceList[a[idx]+1] {
			continue
		}
		spaceList[a[idx]] = false
		spaceList[a[idx]+1] = true
		a[idx] = a[idx] + 1
	}

	for i, ai := range a {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(ai)
	}
	fmt.Println()
}
