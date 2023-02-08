// detail: https://atcoder.jp/contests/abc231/submissions/38716216
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

    var d int
	fmt.Fscan(r, &d)
	fmt.Println(float64(d) / 100.0)
}
