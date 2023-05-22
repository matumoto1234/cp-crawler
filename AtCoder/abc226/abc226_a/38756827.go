// detail: https://atcoder.jp/contests/abc226/submissions/38756827
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	stderr := bufio.NewWriter(os.Stderr)
	defer stdout.Flush()
	defer stderr.Flush()

	var x string
	fmt.Fscan(stdin, &x)

	valList := strings.Split(x, ".")
	before, _ := strconv.ParseInt(valList[0], 10, 64)
	after, _ := strconv.ParseInt(valList[1][0:1], 10, 64)

	if after >= 5 {
		before++
	}

	fmt.Println(before)
}
