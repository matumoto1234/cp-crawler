// detail: https://atcoder.jp/contests/joi2007yo/submissions/7212263
#include<stdio.h>

int a, b, n;
int x[40], y[40];
int done[50][50] = { 0 }, memo[50][50];
int itix, itiy;

int road(int rx, int ry) {
	
	if (done[rx][ry] == 1)return memo[rx][ry];

	for (int i = 0; i < n; i++) {
		if (x[i] == rx && y[i] == ry) {
			return 0;
		}
	}
	if (rx == 0 || ry == 0) {
		return 0;
	}
	if (rx < itix && rx == 1) {
		return 1;
	}
	if (rx < itiy && ry == 1) {
		return 1;
	}
	
	int res;
	res = road(rx - 1, ry) + road(rx, ry - 1);
	done[rx][ry] = 1;
	return memo[rx][ry] = res;
}

int main(void)
{
	

	scanf("%d %d %d", &a, &b, &n);
	itix = a+1;
	itiy = b+1;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		if (x[i] == 1) {
			itix = x[i];
		}
		if (y[i] == 1) {
			itiy = y[i];
		}
	}
	int ans;
	ans = road(a, b);
	printf("%d\n", ans);
	return 0;
}