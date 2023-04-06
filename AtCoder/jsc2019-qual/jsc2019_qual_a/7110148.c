// detail: https://atcoder.jp/contests/jsc2019-qual/submissions/7110148
#include<stdio.h>
int main(void)
{
	int m, d;
	int d1, d2;
	int temp, cnt = 0;

	scanf("%d %d", &m,&d);
	for (int i = 1; i <= m; i++) {
		for (int j = 10; j <= d; j++) {
			temp = j;
			d1 = temp % 10;
			temp /= 10;
			d2 = temp % 10;
			//printf(" %d %d %d\n", i,d2, d1);
			if (d1 >= 2 && d2 >= 2) {
				if (d1 * d2 == i) {
					cnt++;
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}