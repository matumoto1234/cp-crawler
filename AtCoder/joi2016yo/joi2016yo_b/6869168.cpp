// detail: https://atcoder.jp/contests/joi2016yo/submissions/6869168
#include<stdio.h>
int main(void)
{
	int n, m, k;
	int i, j;
	int a[1000], temp;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= m; i++) {//バトン
		for (j = 1; j <= n; j++) {//人
			if (j <= n - 1) {
				if (a[j - 1] % i > a[j] % i) {
					temp = a[j - 1];
					a[j - 1] = a[j];
					a[j] = temp;
				}
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}