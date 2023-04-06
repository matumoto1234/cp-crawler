// detail: https://atcoder.jp/contests/joi2007yo/submissions/7216778
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int a, b;
	int n;
	int x[50], y[50];
	int dp[50][50] = { 0 };
	int minx, miny;

	scanf("%d %d %d", &a, &b, &n);
	minx = a;
	miny = b;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		dp[x[i] - 1][y[i] - 1] = -1;
	}
	
	if (dp[0][1] != -1) {
		dp[0][1] = 1;
	}
	if (dp[1][0] != -1) {
		dp[1][0] = 1;
	}
	
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (dp[i][j] == -1)continue;

			if (i >= 1) {
				if (dp[i - 1][j] != -1) {
					dp[i][j] += dp[i - 1][j];
				}
			}
			if (j >= 1) {
				if (dp[i][j - 1] != -1) {
					dp[i][j] += dp[i][j - 1];
				}
			}

		}
	}
	printf("%d\n", dp[a - 1][b - 1]);

	return 0;
}