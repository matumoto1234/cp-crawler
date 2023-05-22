// detail: https://atcoder.jp/contests/arc035/submissions/39295466
package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	t := make([]int, n)
	for i := range t {
		fmt.Scan(&t[i])
	}

	counter := make(map[int]int)
	for _, ti := range t {
		counter[ti]++
	}

	mod := 1000000007

	factorialList := make([]int, 20000)
	factorialList[0] = 1
	factorialList[1] = 1
	for i := 1; i < 20000; i++ {
		factorialList[i] = (factorialList[i-1] * i) % mod
	}

	// find number of ways
	ways := 1
	for _, cnt := range counter {
		ways *= factorialList[cnt]
		ways %= mod
	}

	// find penalty
	sort.Slice(t, func(i, j int) bool {
		return t[i] < t[j]
	})

	penalty := 0
	time := 0
	for _, ti := range t {
		time += ti
		penalty += time
	}

	fmt.Println(penalty)
	fmt.Println(ways)
}
