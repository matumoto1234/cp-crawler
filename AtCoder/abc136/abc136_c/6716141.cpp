// detail: https://atcoder.jp/contests/abc136/submissions/6716141
#include<stdio.h>
int main(void)
{
	int n, i, j, k;
	int a[100000];
	int max, maxi;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = n - 1; i < 0; i--) {
		if (a[i - 1] - a[i] == 1) {
			a[i - 1]--;
		}
		else if (a[i - 1] - a[i] > 1) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}