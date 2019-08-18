// detail: https://atcoder.jp/contests/abc138/submissions/6991292
#include<stdio.h>
#include<string.h>

/*int max(int x, int y) {
	if (x > y) return x;
	else return y;
}
int min(int x, int y) {
	if (x > y) return y;
	else return x;
}*/

int main(void)
{
	int n, a[100], sum=0;
	double b[100];
	double ans = 0;
	int max=-1;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (max < a[i])max = a[i];
	}
	for (int i = 0; i < n; i++) {
		b[i] = max / a[i];
		sum += b[i];
	}
	ans = (double)max / (double)sum;
	printf("%lf\n", ans);
	return 0;
}