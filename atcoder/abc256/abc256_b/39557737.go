// detail: https://atcoder.jp/contests/abc256/submissions/39557737
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	p := 0
	onSpaceList := make([]bool, 4)
	for _, ai := range a {
		onSpaceList[0] = true
		for i := len(onSpaceList) - 1; i >= 0; i-- {
			if !onSpaceList[i] {
				continue
			}
			if i+ai >= 4 {
				p++
				onSpaceList[i] = false
				continue
			}
			onSpaceList[i+ai] = true
			onSpaceList[i] = false
		}
	}

	fmt.Println(p)
}
