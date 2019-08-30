// detail: https://atcoder.jp/contests/joi2007yo/submissions/7212139
#include<stdio.h>

int a, b, n;
int x[40], y[40];
int done[50][50] = { 0 }, memo[50][50];

int road(int rx, int ry) {
	
	if (done[rx][ry] == 1)return memo[rx][ry];

	if (rx == 1 || ry == 1) {
		return 1;
	}
	for (int i = 0; i < n; i++) {
		if (x[i] == rx && y[i] == ry) {
			return 0;
		}
	}
	int res;
	res = road(rx - 1, ry) + road(rx, ry - 1);
	done[rx][ry] = 1;
	return memo[rx][ry] = res;
}

int main(void)
{
	

	scanf("%d %d %d", &a, &b, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	int ans;
	ans = road(a, b);
	printf("%d\n", ans);
	return 0;
}