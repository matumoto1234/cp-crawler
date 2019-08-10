// detail: https://atcoder.jp/contests/abc137/submissions/6817292
#include<stdio.h>
int main(void)
{
	int a, b;
	int wa, sa, kake;

	scanf("%d %d", &a, &b);
	wa = a + b;
	sa = a - b;
	kake = a * b;
	if (wa > sa) {
		if (wa > kake) {
			printf("%d", wa);
		}
		else {
			printf("%d", kake);
		}
	}
	else {
		if (sa > kake) {
			printf("%d", sa);
		}
		else {
			printf("%d", kake);
		}
	}
	return 0;
}