// detail: https://atcoder.jp/contests/abc133/submissions/6293652
#include<stdio.h>
int main(void)
{
	int n;
	int d;
	int i, j, k;
	int x[15][15];
	int sum;
	int a, jou, su = 1, co;

	sum = jou = co = 0;
	scanf("%d %d", &n, &d);
	for (i = 0; i < n; i++) {
		for (j = 0; j < d; j++) {
			scanf("%d", &x[i][j]);
		}
	}
	for (i = 0; i < n - 1; i++) {
		for (k = i + 1; k < n; k++) {
			for (j = 0; j < d; j++) {
				a = x[i][j] - (x[k][j]);
				sum += a * a;//2乗だから+になる
			}
			jou = 0;
			su = 1;
			while (sum > jou) {
				jou = su * su;
				su++;
				if (sum == jou) {
					co++;
				}
			}
			sum = 0;
		}
	}
	printf("%d\n", co);
	return 0;
}