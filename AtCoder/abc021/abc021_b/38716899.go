// detail: https://atcoder.jp/contests/abc021/submissions/38716899
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    r := bufio.NewReader(os.Stdin)
    w := bufio.NewWriter(os.Stdout)
    defer w.Flush()

	var n int
	fmt.Fscan(r, &n)

	var a, b int
	fmt.Fscan(r, &a, &b)

	var k int
	fmt.Fscan(r, &k)

	p := make([]int, k)
	for i := 0; i < k; i++ {
		fmt.Fscan(r, &p[i])
	}

	isVisited := make(map[int]bool)
	p = append(p, a, b)
	for _, v := range p {
		if isVisited[v] {
			fmt.Println("NO")
			return
		}
		isVisited[v] = true
	}

	fmt.Println("YES")
}
