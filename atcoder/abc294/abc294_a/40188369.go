// detail: https://atcoder.jp/contests/abc294/submissions/40188369
package main

import (
  "fmt"
)

func main() {
  var n int
  fmt.Scan(&n)
  
  a := make([]int, n)
  for i := 0; i < n; i++ {
    fmt.Scan(&a[i])
  }
  
  b := make([]int, 0)

  for i := 0; i < n; i++ {
    if a[i] % 2 == 0 {
      b = append(b, a[i])
    }
  }
  
  for i, v := range b {
    if i > 0 {
      fmt.Print(" ")
    }
    fmt.Print(v)
  }
  fmt.Println()
}