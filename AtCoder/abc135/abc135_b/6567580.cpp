// detail: https://atcoder.jp/contests/abc135/submissions/6567580
#include<stdio.h>
int main(void)
{
	int n, i, j, k;
	int a[50], co = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= n; i++) {
		if (a[i - 1] != i) {
			co++;
		}
	}
	if (co > 2) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
	}
	return 0;
}