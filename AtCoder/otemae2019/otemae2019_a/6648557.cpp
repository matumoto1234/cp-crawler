// detail: https://atcoder.jp/contests/otemae2019/submissions/6648557
#include<stdio.h>
int main(void)
{
	double a, b;

	scanf("%lf %lf", &a, &b);
	a += 0.5;
	if (a > b) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
	return 0;
}