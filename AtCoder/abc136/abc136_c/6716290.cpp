// detail: https://atcoder.jp/contests/abc136/submissions/6716290
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
	for (i = n - 2; i >= 0; i--) {
		if (a[i] - a[i + 1] == 1) {
			a[i]--;
		}
		else if (a[i] - a[i + 1] == 0) {
			continue;
		}
		else if (a[i] - a[i + 1] > 1) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}