// detail: https://atcoder.jp/contests/abc262/submissions/38716605
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

    var n, m int
	fmt.Fscan(r, &n)
	fmt.Fscan(r, &m)

	edgeList := make([][]int, m)
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Fscan(r, &u)
		fmt.Fscan(r, &v)

		edgeList[i] = make([]int, 2)
		edgeList[i][0] = u - 1 // to 0-index
		edgeList[i][1] = v - 1 // to 0-index
	}

	adjacencyMatrix := make([][]int, n)
	for i := 0; i < n; i++ {
		adjacencyMatrix[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		u := edgeList[i][0]
		v := edgeList[i][1]
		adjacencyMatrix[u][v] = 1
		adjacencyMatrix[v][u] = 1
	}

	var count int

	for a := 0; a < n; a++ {
		for b := 0; b < n; b++ {
			for c := 0; c < n; c++ {
				if a < b && b < c {
					if adjacencyMatrix[a][b] == 1 && adjacencyMatrix[b][c] == 1 && adjacencyMatrix[c][a] == 1 {
						count++
					}
				}
			}
		}
	}

	fmt.Println(count)
}
