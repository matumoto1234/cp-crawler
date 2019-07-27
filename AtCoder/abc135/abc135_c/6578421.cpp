// detail: https://atcoder.jp/contests/abc135/submissions/6578421
#include<stdio.h>
int main(void)
{
	int n, i, j, k;
	int a[100001], b[100000];
	long long int sum;
	int temp, temp2;

	scanf("%d", &n);
	for (i = 0; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	sum = 0;
	for (i = 0; i < n; i++) {
		temp = b[i] - a[i];
		if (temp >= 0) {
			sum += a[i];
			b[i] = temp;
			if (i < n - 1) {
				b[i + 1] += temp;
			}
		}
		else {
			sum += b[i];
			a[i] -= b[i];
		}
	}
	temp = a[n] - b[n - 1];
	if (temp >= 0) {
		sum += b[n-1];
	}
	else {
		sum += a[n];
	}
	printf("%d\n", sum);
	return 0;
}