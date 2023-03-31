// detail: https://atcoder.jp/contests/abc074/submissions/40187178
package main

import "fmt"

func main() {
	var A, B, C, D, E, F int
	fmt.Scan(&A, &B, &C, &D, &E, &F)

	// 砂糖水の質量と濃度を最大化する
	var maxConcentration int
	var maxVolume, maxSugar int
	for i := 0; i <= F/(100*A); i++ {
		for j := 0; j <= F/(100*B); j++ {
			water := i*100*A + j*100*B
			if water == 0 {
				continue
			}
			for k := 0; k <= (F-water)/C; k++ {
				for l := 0; l <= (F-water)/D; l++ {
					sugar := k*C + l*D
					if sugar > water*E/100 || water+sugar > F {
						continue
					}
					concentration := 100 * sugar / water
					if concentration > maxConcentration {
						maxConcentration = concentration
						maxVolume = water + sugar
						maxSugar = sugar
					}
				}
			}
		}
	}

	fmt.Printf("%d %d\n", maxVolume, maxSugar)
}
