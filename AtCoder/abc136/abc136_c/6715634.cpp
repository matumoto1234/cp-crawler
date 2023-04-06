// detail: https://atcoder.jp/contests/abc136/submissions/6715634
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
	printf("Yes\n");
	return 0;
}