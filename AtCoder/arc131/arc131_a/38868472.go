// detail: https://atcoder.jp/contests/arc131/submissions/38868472
package main

import (
    "bufio"
    "fmt"
    "os"
)

func pow(x, n int) int {
    if n == 0 {
        return 1
    }
    if n%2 == 0 {
        return pow(x*x, n/2)
    }
    return x * pow(x, n-1)
}

func main() {
    stdin := bufio.NewReader(os.Stdin)
    stdout := bufio.NewWriter(os.Stdout)
	stderr := bufio.NewWriter(os.Stderr)
    defer stdout.Flush()
    defer stderr.Flush()

	var a, b int
    fmt.Fscan(stdin, &a, &b)

    fmt.Println(5 * pow(10, 8) * b + a)
}
