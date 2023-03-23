// detail: https://atcoder.jp/contests/caddi2018b/submissions/39971445
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(stdin, &n)

	a := make([]int, n)
	for i := range a {
		fmt.Fscan(stdin, &a[i])
	}

	if n == 1 {
		if a[0]%2 == 0 {
			fmt.Println("second")
		} else {
			fmt.Println("first")
		}
		return
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})

	k := a[0] - a[1]

	if k%2 == 0 {
		fmt.Println("second")
	} else {
		fmt.Println("first")
	}
}
