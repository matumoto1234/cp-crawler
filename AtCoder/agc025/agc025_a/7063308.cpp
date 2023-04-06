// detail: https://atcoder.jp/contests/agc025/submissions/7063308
#include<stdio.h>
int main(void)
{
	int n;
	int min = 9999999;
	int sa, sum, tmp;

	scanf("%d", &n);
	for (int i = 1; i <= n / 2; i++) {
		sum = 0;
		sa = n - i;
		while (sa > 0) {
			sum += sa % 10;
			sa /= 10;
		}
		tmp = i;
		while (tmp > 0) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (min > sum) {
			min = sum;
		}
	}
	printf("%d\n", min);
	return 0;
}