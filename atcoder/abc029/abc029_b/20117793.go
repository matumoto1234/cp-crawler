// detail: https://atcoder.jp/contests/abc029/submissions/20117793
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func min(a int,b int) int {
	if (a<b) { return a }
	return b
}

func max(a int,b int) int {
	if (a>b) { return a }
	return b
}

func chmin(a *int,b int) { if(*a>b) { *a=b } }
func chmax(a *int,b int) { if(*a<b) { *a=b } }

var stdin = bufio.NewReader(os.Stdin)
var stdout = bufio.NewWriter(os.Stdout)
var stderr = bufio.NewWriter(os.Stderr)

func main(){
	defer stdout.Flush()
	defer stderr.Flush()

	const n = 12
	var ans int
	for i:=0;i<n;i++{
		var s string
		fmt.Fscan(stdin,&s)
		if(strings.Contains(s,"r")==true){
			ans++
		}
	}
	fmt.Fprintln(stdout,ans)
}