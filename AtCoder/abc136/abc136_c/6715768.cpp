// detail: https://atcoder.jp/contests/abc136/submissions/6715768
#include<stdio.h>
int main(void)
{
	int n, i, j, k;
	int a[100000];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n - 2; i++) {
		if (a[i] >= 3) {
			if (a[i + 1] < a[i]) {
				if (a[i + 2] < a[i + 1]) {
					printf("No\n");
					return 0;
				}
			}
		}
	}
	for (i = 0; i < n - 1; i++) {
		if (a[i] >= 2) {
			if (a[i] > a[i + 1]) {
				if (a[i] - a[i + 1] >= 2) {
					printf("No\n");
					return 0;
				}
			}
		}
	}
	printf("Yes\n");
	return 0;
}