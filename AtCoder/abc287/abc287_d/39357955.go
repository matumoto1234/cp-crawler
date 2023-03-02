// detail: https://atcoder.jp/contests/abc287/submissions/39357955
package main

import (
	"bufio"
	"fmt"
	"os"
)

func isSame(ch1, ch2 byte) bool {
	return ch1 == ch2 || ch1 == '?' || ch2 == '?'
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	defer stdout.Flush()

	var s, t string
	fmt.Fscan(stdin, &s, &t)

	front := s[:len(t)]
	frontBound := len(t) + 1

	for i := 0; i < len(t); i++ {
		if !isSame(front[i], t[i]) {
			frontBound = i + 1
			break
		}
	}

	back := s[len(s)-len(t):]
	backBound := -1

	for i := len(t) - 1; i >= 0; i-- {
		if !isSame(back[i], t[i]) {
			backBound = i
			break
		}
	}

	for x := 0; x <= len(t); x++ {
		if backBound < x && x < frontBound {
			fmt.Fprintln(stdout, "Yes")
		} else {
			fmt.Fprintln(stdout, "No")
		}
	}
}
