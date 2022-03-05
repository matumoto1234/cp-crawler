// detail: https://atcoder.jp/contests/arc119/submissions/29858504
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

    var n int64

    fmt.Fscan(r, &n)
  
    ans:=int64(2000000000000000000)
  
    for b:=int64(0);b<62;b+=1 {
      v1:=int64(1<<b)
      
      for a:=int64(0);int64(a*v1) <= n; a+=1 {
        v2:=int64(a*v1)
        c:=n-v2
        
        if ans>a+b+c {
          ans=a+b+c
        }
        
        a+=1
      }
    }

    fmt.Fprintln(w, ans)
}