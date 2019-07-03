// detail: https://atcoder.jp/contests/joi2017yo/submissions/6223602
#include<stdio.h>
int main(void)
{
	int a, b, c, d, e;
	int i;
	int ondo = 0, time = 0;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	ondo = a;
	if (ondo < 0) {
		while (ondo < 0) {
			ondo++;
			time += c;
		}
	}
	if (ondo == 0) {
		time += d;
	}
	while (ondo < b) {
		ondo++;
		time += e;
	}
	printf("%d\n", time);
	return 0;
}