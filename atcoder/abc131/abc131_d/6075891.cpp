// detail: https://atcoder.jp/contests/abc131/submissions/6075891
#include<stdio.h>
int main(void)
{
	int n;
	long int a[20000], b[20000];
	int i, j, k;
	long int sum;
	int max;

	max = sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%ld %ld", &a[i], &b[i]);
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