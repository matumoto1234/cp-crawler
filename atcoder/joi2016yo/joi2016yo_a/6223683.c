// detail: https://atcoder.jp/contests/joi2016yo/submissions/6223683
#include<stdio.h>
int main(void)
{
	int a, b, c, d, e, f;
	int i;
	int min1;
	int all;

	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	all = a + b + c + d + e + f;
	min1 = a;
	if (min1 > b) {
		min1 = b;
	}
	if (min1 > c) {
		min1 = c;
	}
	if (min1 > d) {
		min1 = d;
	}
	if (e > f) {
		all -= (min1 + f);
	}
	else {
		all -= (min1 + e);
	}
	printf("%d\n", all);
	return 0;
}