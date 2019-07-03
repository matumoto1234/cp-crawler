// detail: https://atcoder.jp/contests/joi2014yo/submissions/6223793
#include<stdio.h>
int main(void)
{
	int a, b, c, d, e;
	int ave;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	if (a < 40) {
		a = 40;
	}
	if (b < 40) {
		b = 40;
	}
	if (c < 40) {
		c = 40;
	}
	if (d < 40) {
		d = 40;
	}
	if (e < 40) {
		e = 40;
	}
	ave = (a + b + c + d + e)/5;
	printf("%d\n", ave);
	return 0;
}