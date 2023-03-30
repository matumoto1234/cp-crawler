// detail: https://atcoder.jp/contests/tenka1-2012-qualB/submissions/40168181
package main

import (
	"fmt"
	"strings"
	"unicode"
)

func takeWhile(s string, fn func(r rune) bool) string {
	res := ""

	for _, r := range s {
		if !fn(r) {
			break
		}
		res = res + string(r)
	}

	return res
}

func reverse(s string) string {
	r := []rune(s)
	res := ""

	for i := 0; i < len(r); i++ {
		j := len(r) - 1 - i
		res = res + string(r[j])
	}

	return res
}

func isWord(s string) bool {
	if s == "" {
		return true
	}

	if unicode.IsDigit(rune(s[0])) || unicode.IsUpper(rune(s[0])) {
		return false
	}

	isValid := func(r rune) bool {
		return unicode.IsDigit(r) || unicode.IsLower(r)
	}

	for _, r := range s {
		if !isValid(r) {
			return false
		}
	}

	return true
}

func isLowerCamel(s string) bool {
	t := strings.Trim(s, "_")

	word := ""
	wordList := make([]string, 0)
	for _, r := range t {
		if unicode.IsUpper(r) {
			wordList = append(wordList, word)
			word = ""
			continue
		}
		word = word + string(r)
	}

	if word != "" {
		wordList = append(wordList, word)
	}

	for _, w := range wordList {
		if !isWord(w) {
			return false
		}
	}

	head := wordList[0]
	if head != "" && !unicode.IsLower(rune(head[0])) {
		return false
	}

	return true
}

func isSnake(s string) bool {
	wordList := strings.Split(s, "_")

	for _, w := range wordList {
		if !isWord(w) {
			return false
		}
	}

	return true
}

func toLowerCamel(s string) string {
	t := strings.Trim(s, "_")

	wordList := strings.Split(t, "_")

	// join
	res := wordList[0]

	for i := 1; i < len(wordList); i++ {
		w := wordList[i]

		if w == "" {
			continue
		}

		u := string(unicode.ToUpper(rune(w[0])))
		res = res + (u + w[1:])
	}

	pre := takeWhile(s, func(r rune) bool {
		return r == rune('_')
	})

	suf := takeWhile(reverse(s), func(r rune) bool {
		return r == rune('_')
	})

	res = pre + res + suf

	return res
}

func toSnake(s string) string {
	word := ""
	wordList := make([]string, 0)

	// split
	for _, r := range s {
		if unicode.IsUpper(r) {
			wordList = append(wordList, word)
			l := string(unicode.ToLower(r))
			word = l
			continue
		}
		word = word + string(r)
	}

	if word != "" {
		wordList = append(wordList, word)
	}

	return strings.Join(wordList, "_")
}

func main() {
	var s string
	fmt.Scan(&s)

	if isLowerCamel(s) {
		fmt.Println(toSnake(s))
		return
	}

	if isSnake(s) {
		fmt.Println(toLowerCamel(s))
		return
	}

	fmt.Println(s)
}
