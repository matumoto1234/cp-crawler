// detail: https://atcoder.jp/contests/abc137/submissions/6833370
#include<stdio.h>
#include<string.h>
int main(void)
{
	int n, i, j, k, h;
	double ans = 0.0;
	static char a[200001][11];
	char temp, wk[11];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	for (i = 0; i < n; i++) {//調べるaの配列
		/*文字列１行のソート*/
		for (j = 0; j < 9; j++) {
			for (int jj = j + 1; jj < 10; jj++) {
				if (strcmp(&a[i][j], &a[i][jj]) > 0) {
					temp = a[i][j];
					a[i][j] = a[i][jj];
					a[i][jj] = temp;
				}
			}
		}
		//printf("a=%s\n", a[i]);
	}
	/*各文字列のソート*/
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (strcmp(a[i], a[j]) > 0) {
				strcpy(wk, a[i]);
				strcpy(a[i], a[j]);
				strcpy(a[j], wk);
			}
		}
	}
	/*各文字列の前後で比較*/
	for (i = 1; i < n-1; i++) {
		if (i + 1 < n) {
			if (strcmp(a[i], a[i + 1]) == 0) {
				ans++;
			}
		}
		if (i - 1 >= 0) {
			if (strcmp(a[i], a[i - 1]) == 0) {
				ans++;
			}
		}
	}
	/*for (i = 0; i < n; i++) {
		printf("a>>%s\n", a[i]);
	}*/
	printf("%.0lf\n", ans);
	return 0;
}