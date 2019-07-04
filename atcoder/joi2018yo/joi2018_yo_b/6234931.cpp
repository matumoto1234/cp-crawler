// detail: https://atcoder.jp/contests/joi2018yo/submissions/6234931
#include<stdio.h>
int main(void)
{
	int n, i;
	int a[101];
	int k, co = 0;
	int max = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		if (a[i] == 1) {
			co++;
		}
		else {
			co = 0;
		}
		if (max < co) {
			max = co;
		}
	}
	printf("%d\n", max + 1);
	return 0;
}