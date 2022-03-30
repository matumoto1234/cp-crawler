// detail: https://atcoder.jp/contests/ddcc2020-qual/submissions/30560853
package main

import (
	"fmt"
	"bufio"
	"os"
)

func calc_award(place int) int {
	earlgray := 100000

	if place == 1 {
		return 3 * earlgray
	} else if place == 2 {
		return 2 * earlgray
	} else if place == 3 {
		return 1 * earlgray
	}

	return 0
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	defer stdout.Flush()

	var x, y int

	fmt.Fscan(stdin, &x, &y)

	sum := calc_award(x)
	sum += calc_award(y)

	if x == 1 && y == 1 {
		sum += 400000
	}

	fmt.Fprintln(stdout, sum)
}