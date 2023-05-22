// detail: https://atcoder.jp/contests/arc135/submissions/39791946
package main

import "fmt"

var memo map[int]int

const mod = 998244353

func dfs(x int) int {
	if x == 1 || x == 2 || x == 3 {
		return x
	}

	if _, ok := memo[x]; ok {
		return memo[x]
	}

	floor := x / 2
	ceil := (x + (2 - 1)) / 2

	res1 := dfs(floor)
	res2 := dfs(ceil)

	memo[x] = (res1 * res2) % mod
	return memo[x]
}

func main() {
	var x int
	fmt.Scan(&x)

	memo = make(map[int]int)

	fmt.Println(dfs(x))
}
