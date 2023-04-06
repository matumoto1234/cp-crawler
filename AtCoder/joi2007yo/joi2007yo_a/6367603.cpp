// detail: https://atcoder.jp/contests/joi2007yo/submissions/6367603
#include<stdio.h>
int main(void)
{
	int a1, a2, a3, a4;
	int b1, b2, b3, b4;
	int sum1, sum2;
	
	scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
	scanf("%d %d %d %d", &b1, &b2, &b3, &b4);
	sum1 = a1 + a2 + a3 + a4;
	sum2 = b1 + b2 + b3 + b4;
	if (sum1 >= sum2) {
		printf("%d\n", sum1);
	}
	else {
		printf("%d\n", sum2);
	}
	return 0;
}