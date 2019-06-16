// detail: https://atcoder.jp/contests/abc130/submissions/5957661
#include<stdio.h>
int main(void)
{
	int n;
	int x;
	int s[101];
	int i;
	int x1 = 0, co = 0;

	scanf("%d %d", &n, &x);
	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	for (i = 0; i < n; i++) {
		if (x1 <= x) {
			co++;
		}
		x1 = x1 + s[i];
		
	}
	if (x1 <= x) {
		co++;
	}
	printf("%d\n", co);
	return 0;
}