// detail: https://atcoder.jp/contests/joisc2007/submissions/6515086
#include <stdio.h>
int main(void)
{
	int n, i, j;
	int a[100000];
	int list[101] = { 0 };

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		list[a[i] - 1]++;
	}
	list[100] = 1;
	for (i = 99; i >= 0; i--) {
		list[i] += list[i + 1];
	}
	for (i = 0; i < n; i++) {
		printf("%d\n", list[a[i]]);
	}
	return 0;
}