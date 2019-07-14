// detail: https://atcoder.jp/contests/joi2008yo/submissions/6367548
#include<stdio.h>
int main(void)
{
	int co=0;
	int n;
	
	scanf("%d", &n);
	n = 1000 - n;
	if (500 <= n) {
		co += n / 500;
		n = n % 500;
	}
	if (100 <= n) {
		co += n / 100;
		n = n % 100;
	}
	if (50 <= n) {
		co += n / 50;
		n = n % 50;
	}
	if (10 <= n) {
		co += n / 10;
		n = n % 10;
	}
	if (5 <= n) {
		co += n / 10;
		n = n % 5;
	}
	if (1 <= n) {
		co += n;
	}
	printf("%d\n", co);
	return 0;
}