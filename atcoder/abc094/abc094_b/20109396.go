// detail: https://atcoder.jp/contests/abc094/submissions/20109396
package main

import(
	"fmt"
	"bufio"
	"os"
)

var stdin = bufio.NewReader(os.Stdin)
var stdout = bufio.NewWriter(os.Stdout)
var stderr = bufio.NewWriter(os.Stderr)

func min(a,b int) int{
	if a<b {
		return a
	}
	return b
}

func main(){
	defer stdout.Flush()
	defer stderr.Flush()

	const MAXN = 100

	var n,m,x int
	fmt.Fscan(stdin,&n)
	fmt.Fscan(stdin,&m)
	fmt.Fscan(stdin,&x)
	x--
	//fmt.Fprintf(stderr,"x:%d\n",x)

	var a[MAXN] int
	for i:=0;i<m;i++{
		var in int
		fmt.Fscan(stdin,&in)
		in--
		a[in]=1
	}

	v1:=0
	for i:=x;i<n;i++{
		v1+=a[i]
	}

	v2:=0
	for i:=x;i>=0;i--{
		v2+=a[i]
	}

	fmt.Fprintf(stdout,"%d\n",min(v1,v2))
}