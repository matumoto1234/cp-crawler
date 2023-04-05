// detail: https://atcoder.jp/contests/joi2015yo/submissions/6223728
#include<stdio.h>
int main(void)
{
	int a, b, c, d, p;
	int max, ryoukin;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);
	max = p * a;
	if (p > c) {
		ryoukin = (p - c)*d;
		ryoukin += b;
	}
	else {
		ryoukin = b;
	}
	if (ryoukin > max) {
		printf("%d\n", max);
	}
	else {
		printf("%d\n", ryoukin);
	}
	return 0;
}