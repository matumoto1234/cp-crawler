// detail: https://atcoder.jp/contests/abc120/submissions/4456930
#include<stdio.h>
int main(void)
{
	int a, b, k,yaku[1000],su;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &k);
	int i,co=0;
	for (i = 1; i <= 100; i++) {
		if (a%i == 0) {
			if (b%i == 0) {
				yaku[co]=i;
				co++;
			}
		}
	}
	su = yaku[co - k];
	printf("%d\n", su);
	return 0;
}