// detail: https://atcoder.jp/contests/abc116/submissions/20111667
package main

import (
	"bufio"
	"fmt"
	"os"
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

func solve(a int) int{
	if(a%2==0){
		return a/2
	}
	return 3*a+1
}

func main(){
	defer stdout.Flush()
	defer stderr.Flush()

	var s int
	fmt.Fscan(stdin,&s)
	mp:=make(map[int]bool)
	mp[s]=true
	i:=1
	prev:=s
	for {
		v:=solve(prev)
		if(mp[v]==true){
			break;
		}
		mp[v]=true
		prev=v
		i++
	}
	//fmt.Fprintln(stderr,mp)
	fmt.Fprintf(stdout,"%d\n",i+1)
}