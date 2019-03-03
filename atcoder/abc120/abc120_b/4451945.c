// detail: https://atcoder.jp/contests/abc120/submissions/4451945
#include<stdio.h>
int main(void)
{
	int a, b, k,yaku[100];
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &k);
	int i,co=0;
	for (i = 0; i < 100; i++) {
		if (a%i == 0) {
			if (b%i == 0) {
				i = yaku[co];
				co++;
			}
		}
	}
	k = yaku[k];
	printf("%d\n", k);
	return 0;
}