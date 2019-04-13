// detail: https://atcoder.jp/contests/abc124/submissions/4940976
#include<stdio.h>
int main(void)
{
	int a, b, sum = 0;
	int i;

	scanf("%d", &a);
	scanf("%d", &b);
	for (i = 0; i < 2; i++) {
		if (a < b) {
			sum = sum + b;
			b = b - 1;
		}
		else if (a >= b) {
			sum = sum + a;
			a = a - 1;
		}
	}
	printf("%d\n", sum);
	return 0;
}