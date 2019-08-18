// detail: https://atcoder.jp/contests/abc138/submissions/7009320
#include<stdio.h>
#include<string.h>
double a[50];
int max = -1, n;
double memo[51][51];
int done[51][51] = { 0 };

double maxk(double x, double y) {
	if (x > y) return x;
	else return y;
}

double value(int i, int j) {
	//if (done[i][j])return memo[i][j];
	if (i == n-1 || j == n-1) {
		return (a[i]+a[j])/2.0;
	}
	if (!(done[i][j])&&!(done[j][i])) {
		//printf("i>%d j>%d h>%lf\n", i, j, (a[i] + a[j]) / 2.0);
		int res;
		res = maxk(value(i + 1, j), value(i, j + 1));
		done[i][j] = 1;
		return memo[i][j] = res;
	}
	else {
		return memo[i][j];
	}
}

int main(void)
{
	int temp;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
	}
	printf("%lf\n", value(0,0));
	return 0;
}