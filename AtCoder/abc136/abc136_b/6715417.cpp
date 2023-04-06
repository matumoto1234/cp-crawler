// detail: https://atcoder.jp/contests/abc136/submissions/6715417
#include<stdio.h>
int main(void)
{
	int n;
	int sum;

	scanf("%d", &n);
	if (n >= 100000) {
		sum = 100000 - 10000 + 1000 - 100 + 9;
	}
	else if (n >= 10000) {
		sum = 909 + n - 9999;
	}
	else if (n >= 1000) {
		sum = 1000 - 100 + 9;
	}
	else if (n >= 100) {
		sum = 9 + n - 99;
	}
	else if (n >= 10) {
		sum = 9;
	}
	else {
		sum = n;
	}
	printf("%d\n", sum);
	return 0;
}