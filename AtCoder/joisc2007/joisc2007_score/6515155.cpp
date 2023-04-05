// detail: https://atcoder.jp/contests/joisc2007/submissions/6515155
#include <stdio.h>
int main(void)
{
	int n, i;
	int a[100000];
	int list[102] = { 0 };

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		list[a[i]]++;
	}
	list[101] = 1;
	for (i = 100; i >= 0; i--) {
		list[i] += list[i + 1];
	}
	for (i = 0; i < n; i++) {
		printf("%d\n", list[a[i]+1]);
	}
	return 0;
}