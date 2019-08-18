// detail: https://atcoder.jp/contests/abc138/submissions/6994903
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
	int n, a[200], sum=0;
	double ans = 0;
	int max=-1;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		if (max < a[i])max = a[i];
	}
	for (int i = 0; i < n; i++) {
		sum += (double)max / (double)a[i];
	}
	ans = (double)max / (double)sum;
	printf("%.5lf\n", ans);
	return 0;
}