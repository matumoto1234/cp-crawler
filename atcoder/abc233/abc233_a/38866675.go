// detail: https://atcoder.jp/contests/abc233/submissions/38866675
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    stdin := bufio.NewReader(os.Stdin)
    stdout := bufio.NewWriter(os.Stdout)
	stderr := bufio.NewWriter(os.Stderr)
    defer stdout.Flush()
    defer stderr.Flush()

	var x, y int
    fmt.Fscan(stdin, &x, &y)

	if x >= y {
		fmt.Println(0)
		return
	}

	fmt.Fprintln(stdout, ((y - x) + 9) / 10)
}
