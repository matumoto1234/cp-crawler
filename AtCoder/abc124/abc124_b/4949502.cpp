// detail: https://atcoder.jp/contests/abc124/submissions/4949502
#include<stdio.h>
int main(void)
{
	int n;
	int a[20];
	int i, j, co = 0, flag;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = a[n - 1]; i > 0; i--) {
		flag = 0;
		for (j = a[n - 2]; j > 0; j--) {
			if (a[i] >= a[j]) {
				flag = 1;
			}
			else if (a[i] < a[j]) {
				flag = 0;
			}
		}
		if (flag == 1) {
			co++;
		}
	}
	printf("%d\n", co);
	return 0;
}