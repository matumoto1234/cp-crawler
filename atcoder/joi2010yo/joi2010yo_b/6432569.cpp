// detail: https://atcoder.jp/contests/joi2010yo/submissions/6432569
#include <stdio.h>
int main(void)
{
	int n, m;
	int i, j;
	int a[1000], b[1000];
	int now = 0, co = 0, temp;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	for (i = 0; i < m; i++) {
		co++;
		now += b[i];
		if (now >= n) {
			break;
		}
		temp = now;
		now += a[temp];
		if (now >= n) {
			break;
		}
	}
	printf("%d\n", co);
	return 0;
}