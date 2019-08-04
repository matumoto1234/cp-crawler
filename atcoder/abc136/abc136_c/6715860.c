// detail: https://atcoder.jp/contests/abc136/submissions/6715860
#include<stdio.h>
int main(void)
{
	int n, i, j, k;
	int a[100000];
	int max;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	max = -1;
	for (i = 0; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	for (i = 0; i < n; i++) {
		if (a[i] < max - 1) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}