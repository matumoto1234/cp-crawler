// detail: https://atcoder.jp/contests/abc117/submissions/4172219
#include<stdio.h>
int main(void)
{
	int n, sum, i, max,a[10];
	scanf("%d", &n);
        max=0;
	for (i = 0; i < n; i++) {
		scanf("%d", a[i]);
		sum = sum + a[i];
		if (max < a[i]) {
			max = a[i];
		}
	}
	sum = sum - max;
	if (max < sum) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}