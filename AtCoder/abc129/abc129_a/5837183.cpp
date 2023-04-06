// detail: https://atcoder.jp/contests/abc129/submissions/5837183
#include<stdio.h>
int main(void)
{
	int i, a, b, c;
	int min;

	scanf("%d %d %d", &a, &b, &c);
	min = a + b;
	if (min > a + c) {
		min = a + c;
	}
	if (min > b + c) {
		min = b + c;
	}
	printf("%d\n", min);
	return 0;
}