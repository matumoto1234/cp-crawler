// detail: https://atcoder.jp/contests/joi2017yo/submissions/6349034
#include<stdio.h>
int main(void)
{
	int n, m, a[1000], b[1000], i;
	int sum, max, sa;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	max = sum = 0;
	for (i = 0; i < m; i++) {
		sa = n - a[i];
		if (sa > 0) {
			sum += sa;
		}
		if (max < sa) {
			max = sa;
		}
	}
	printf("%d\n", sum - max);
	return 0;
}
