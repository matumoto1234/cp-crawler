// detail: https://atcoder.jp/contests/abc153/submissions/46939042
package main

import (
    "fmt"
    "sort"
)

func main() {
    var n, k int
    fmt.Scan(&n, &k)

    h := make([]int, n)
    for i := range h {
      fmt.Scan(&h[i])
    }

    sort.Slice(h, func(i, j int) bool {
      return h[i] > h[j]
    })

    sum := 0

    for i := k; i < len(h); i++ {
      sum += h[i]
    }

    fmt.Println(sum)
}