// detail: https://atcoder.jp/contests/code-festival-2014-final/submissions/40148360
package main

import (
	"bufio"
	"fmt"
	"os"
)

func isValid(a, b, c int) bool {
	if a < b && b > c {
		return true
	}
	if a > b && b < c {
		return true
	}
	return false
}

func main() {
	stdin := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(stdin, &n)

	r := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(stdin, &r[i])
	}

	validGraph := make([]int, 0)

	validGraph = append(validGraph, r[0])

	for i := 1; i < n-1; i++ {
		if isValid(r[i-1], r[i], r[i+1]) {
			validGraph = append(validGraph, r[i])
		}
	}

	validGraph = append(validGraph, r[n-1])

	if len(validGraph) < 3 {
		fmt.Println(0)
	} else {
		fmt.Println(len(validGraph))
	}
}
