// detail: https://atcoder.jp/contests/arc129/submissions/38867249
package main

import (
    "bufio"
    "fmt"
    "os"
)

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func dist(l, r, x int) int {
    if x < l {
        return l - x
    }
    if l <= x && x <= r {
        return 0
    }
    return x - r
}

func main() {
    stdin := bufio.NewReader(os.Stdin)
    stdout := bufio.NewWriter(os.Stdout)
	stderr := bufio.NewWriter(os.Stderr)
    defer stdout.Flush()
    defer stderr.Flush()

	var n int
    fmt.Fscan(stdin, &n)

    lrList := make([][2]int, n)
    for i := 0; i < n; i++ {
        fmt.Fscan(stdin, &lrList[i][0], &lrList[i][1])
    }

    INF := 1 << 60

    maxLeft := -INF
    minRight := INF
    for i := 0;i<n;i++{
        l, r := lrList[i][0], lrList[i][1]
        maxLeft = max(maxLeft, l)
        minRight = min(minRight, r)

        if maxLeft <= minRight {
            fmt.Fprintln(stdout, 0)
            continue
        }

        x := (maxLeft + minRight) / 2
        ans := max(abs(x - minRight), abs(x - maxLeft))
        fmt.Fprintln(stdout, ans)
    }
}

