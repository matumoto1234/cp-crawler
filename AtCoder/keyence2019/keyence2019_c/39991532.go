// detail: https://atcoder.jp/contests/keyence2019/submissions/39991532
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func sumList(a []int) int {
	var sum int
	for _, ai := range a {
		sum += ai
	}
	return sum
}

func isAllElementsGreaterOrEqual(a, b []int) bool {
	for i:=0;i<len(a);i++ {
		if a[i] < b[i] {
			return false
		}
	}
	return true
}

func main() {
	stdin := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(stdin, &n)

	a := make([]int, n)
	for i := range a {
		fmt.Fscan(stdin, &a[i])
	}

	b := make([]int, n)
	for i := range b {
		fmt.Fscan(stdin, &b[i])
	}

	if sumList(b) > sumList(a) {
		fmt.Println(-1)
		return
	}

	if isAllElementsGreaterOrEqual(a, b) {
		fmt.Println(0)
		return
	}

	diffList := make([]int, n)
	for i := 0; i < n; i++ {
		diffList[i] = a[i] - b[i]
	}

	sort.Slice(diffList, func(i, j int) bool {
		return diffList[i] > diffList[j]
	})

	var diffListIndex int
	var ans int

	for i := 0; i < n; i++ {
		if a[i] >= b[i] {
			continue
		}

		ans++
		use := b[i] - a[i]

		for j := diffListIndex; j < n; j++ {
			if diffList[j] >= use {
				diffList[j] -= use
				diffListIndex = j
				break
			}

			use -= diffList[j]
			diffList[j] = 0
		}
	}

	ans += diffListIndex + 1

	fmt.Println(ans)
}
