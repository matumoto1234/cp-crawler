// detail: https://atcoder.jp/contests/abc119/submissions/4374967
#include<stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	double x[15],y=0;
	char u[15];
	int i;
	for (i = 0; i < n; i++) {
		scanf("%lf", x[i]);
		scanf("%c", u[i]);
		if (u[i] == 'JPY') {
			y = y + x[i];
		}
		else if (u[i] == 'BTC') {
			x[i] = x[i] * 380000;
			y = y + x[i];
		}
	}
	printf("%lf\n", y);
	return 0;
}