// detail: https://atcoder.jp/contests/abc238/submissions/39435668
package main

import "fmt"

func f(x int) int {
	// x以下で最大の10のべき乗
	pow10 := 1
	for {
		if pow10 > x {
			pow10 /= 10
			break
		}
		pow10 *= 10
	}

	return x - pow10 + 1
}

func naive(n int) int {
	mod := 998244353
	sum := 0
	for i := 1; i <= n; i++ {
		sum += f(i)
		sum %= mod
	}
	return sum
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func sumOfArithmeticSequence(first, last, len, mod int) int {
	first %= mod
	last %= mod
	len %= mod
	return (first + last) * len / 2 % mod
}

func main() {
	var n int
	fmt.Scan(&n)

	const mod = 998244353

	sum := 0
	pow10 := 1
	for i := 0; pow10 <= n; i++ {
		first := pow10 - (pow10 - 1)
		last := min(pow10*10-1, n) - (pow10 - 1)
		len := last - first + 1

		sum += sumOfArithmeticSequence(first, last, len, mod)
		sum %= mod

		pow10 *= 10
	}
	fmt.Println(sum)
}
