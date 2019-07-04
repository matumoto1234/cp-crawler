// detail: https://atcoder.jp/contests/joi2019yo/submissions/6234683
#include<stdio.h>
int main(void)
{
	int n, x[100], m, a[100];
	int i;

	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++) {
		if (x[a[i] - 1] <= 2018 && x[a[i]] - x[a[i] - 1] != 1) {
			x[a[i] - 1]++;
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d\n", x[i]);
	}
	return 0;
}