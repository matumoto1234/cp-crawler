// detail: https://atcoder.jp/contests/agc022/submissions/39156626
package main

import "fmt"

// Minimum EXcluded string
func mexString(s string) byte {
	counter := make(map[byte]int, 0)
	for i := 0; i < len(s); i++ {
		counter[s[i]]++
	}

	alphabet := "abcdefghijklmnopqrstuvwxyz"
	for i := 0; i < len(alphabet); i++ {
		if _, ok := counter[alphabet[i]]; !ok {
			return alphabet[i]
		}
	}

	return 0
}

func findIndex(s string, c byte) int {
	for i := 0; i < len(s); i++ {
		if s[i] == c {
			return i
		}
	}
	return -1
}

func nextAlphabet(c byte) byte {
	if c == 'z' {
		return 'a'
	}
	return c + 1
}

func main() {
	var s string
	fmt.Scan(&s)

	if len(s) < 26 {
		fmt.Println(s + string(mexString(s)))
		return
	}
	if s == "zyxwvutsrqponmlkjihgfedcba" {
		fmt.Println(-1)
		return
	}

	zi := findIndex(s, 'z')
	fmt.Println(s[:zi-1] + string(nextAlphabet(s[zi-1])))
}
