// detail: https://atcoder.jp/contests/joi2018yo/submissions/6223495
#include<stdio.h>
int main(void)
{
	int n, a, b, c, d;
	int maxm;
	int sum = 0, money = 0;

	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	while (n > sum) {
		sum += a;
		money += b;
	}
	maxm = money;
	sum = 0;
	money = 0;
	while (n > sum) {
		sum += c;
		money += d;
	}
	if (maxm < money) {
		printf("%d\n", maxm);
	}
	else {
		printf("%d\n", money);
	}
	return 0;
}