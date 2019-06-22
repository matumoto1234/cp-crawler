// detail: https://atcoder.jp/contests/abc131/submissions/6077073
#include<stdio.h>
int main(void)
{
	int n;
	int a[200000], b[200000];
	int i, j, k;
	long int sum;
	int max;

	max = sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (i = 0; i < n; i++) {
		if (max < b[i]) {
			max = b[i];
		}
		sum += a[i];
	}
	if (sum > max) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
	return 0;
}