// detail: https://atcoder.jp/contests/joi2018yo/submissions/6223403
#include<stdio.h>
int main(void)
{
	int n, a, b, c, d;
	double x1, y1;
	int sum = 0, money = 0;

	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	x1 = (double)b / (double)a;
	y1 = (double)d / (double)c;
	if (x1 > y1) {
		while (n > sum) {
			sum += a;
			money += b;
		}
	}
	else {
		while (n > sum) {
			sum += c;
			money += d;
		}
	}
	printf("%d\n", money);
	return 0;
}