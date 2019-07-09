// detail: https://atcoder.jp/contests/joi2015yo/submissions/6322126
#include<stdio.h>
int main(void)
{
	int n, m;
	int a[100],b[100][100];
	int i, j;
	int sum[100] = { };

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (a[i] != b[i][j]) {
				sum[a[i]-1]++;
			}
			if (a[i] == b[i][j]) {
				sum[j]++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d\n", sum[i]);
	}
	return 0;
}