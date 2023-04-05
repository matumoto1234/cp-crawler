// detail: https://atcoder.jp/contests/abc093/submissions/6744396
#include<stdio.h>
int main(void)
{
	int a, b, k, i, j;
	int ans[200];
	int co, ansi, flag, temp;

	scanf("%d %d %d", &a, &b, &k);
	if (b <= k) {
		for (i = a; i <= b; i++) {
			printf("%d\n", i);
		}
		return 0;
	}
	co = ansi = 0;
	for (i = a; i <= b; i++) {
		co++;
		if (co > k) {
			break;
		}
		ans[ansi++] = i;
	}
	co = 0;
	for (i = b; i >= a; i--) {
		flag = 0;
		co++;
		if (co > k) {
			break;
		}
		for (j = 0; j < ansi; j++) {
			if (ans[j] == i) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			ans[ansi++] = i;
		}
	}
	for (i = 0; i < ansi - 1; i++) {
		for (j = i + 1; j < ansi; j++) {
			if (ans[i] > ans[j]) {
				temp = ans[i];
				ans[i] = ans[j];
				ans[j] = temp;
			}
		}
	}
	for (i = 0; i < ansi; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}