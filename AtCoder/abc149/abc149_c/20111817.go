// detail: https://atcoder.jp/contests/abc149/submissions/20111817
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

func main(){
	defer stdout.Flush()
	defer stderr.Flush()

	const N = 100000+5
	var x int
	fmt.Fscan(stdin,&x)
	var a[N+1] bool
	for i:=2;i<=N;i++{
		a[i]=true
	}

	for i:=2;i<=N;i++{
		if(a[i]==false){
			continue;
		}

		for j:=2*i;j<=N;j+=i{
			a[j]=false;
		}
	}

	var ans=x;
	for a[ans]==false{
		ans++
	}
	fmt.Fprintf(stdout,"%d\n",ans)
}