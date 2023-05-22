// detail: https://atcoder.jp/contests/tenka1-2012-qualC/submissions/39992521
package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

type Card struct {
	Suit   string
	Number int
}

func (c Card) String() string {
	return c.Suit + toNumberStr(c.Number)
}

func toNumberStr(n int) string {
	switch n {
	case 1:
		return "A"
	case 11:
		return "J"
	case 12:
		return "Q"
	case 13:
		return "K"
	default:
		return fmt.Sprint(n)
	}
}

func toNumber(s string) int {
	switch s {
	case "A":
		return 1
	case "T":
		return 10
	case "J":
		return 11
	case "Q":
		return 12
	case "K":
		return 13
	default:
		n, _ := strconv.ParseInt(s, 10, 64)
		return int(n)
	}
}

// ロイヤルストレートフラッシュを作ったときの捨て札を返す
func discardListUntilRoyalStraightFlush(cardList []Card, suit string) []Card {
	exists := make([]bool, 5)

	discardList := make([]Card, 0)

	for i := 0; i < len(cardList); i++ {
		dispose := true
		if cardList[i].Suit == suit {
			switch cardList[i].Number {
			case 10:
				exists[0] = true
				dispose = false
			case 11:
				exists[1] = true
				dispose = false
			case 12:
				exists[2] = true
				dispose = false
			case 13:
				exists[3] = true
				dispose = false
			case 1:
				exists[4] = true
				dispose = false
			}
		}

		if exists[0] && exists[1] && exists[2] && exists[3] && exists[4] {
			return discardList
		}

		if dispose {
			discardList = append(discardList, cardList[i])
		}
	}

	return discardList
}

func main() {
	var s string
	fmt.Scan(&s)

	cardList := make([]Card, 0)

	// "10"を"T"に変換
	s = strings.ReplaceAll(s, "10", "T")

	for i := 0; i < len(s); i += 2 {
		c := Card{
			Suit:   string(s[i]),
			Number: toNumber(string(s[i+1])),
		}

		cardList = append(cardList, c)
	}

	spade := discardListUntilRoyalStraightFlush(cardList, "S")
	heart := discardListUntilRoyalStraightFlush(cardList, "H")
	diamond := discardListUntilRoyalStraightFlush(cardList, "D")
	club := discardListUntilRoyalStraightFlush(cardList, "C")

	a := [][]Card{spade, heart, diamond, club}

	sort.Slice(a, func(i, j int) bool {
		return len(a[i]) < len(a[j])
	})

	if len(a[0]) == 0 {
		fmt.Println(0)
	} else {
		for _, ai := range a[0] {
			fmt.Print(ai)
		}
		fmt.Println()
	}
}
