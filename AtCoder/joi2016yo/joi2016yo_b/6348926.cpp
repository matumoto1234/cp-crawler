// detail: https://atcoder.jp/contests/joi2016yo/submissions/6348926
#include<stdio.h>
int main(void)
{
	int n, m, i, a[100];
	int k, temp;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	i = 1;
	for (k = 1; k <= m; k++) {
		for(i = 0; i < n-1; i++) {
			if (a[i] % k > a[i + 1] % k) {
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}
