// detail: https://atcoder.jp/contests/tenka1-2019-beginner/submissions/5046541
#include<stdio.h>
int main(void)
{
	int n;
	int i, co = 0;
	char a[100001];

	scanf("%d", &n);
	scanf("%s", a);
	for (i = 0; i < n; i++) {
		if (a[i] == '.') {
			if (a[i - 1] == '#') {
				a[i - 1] = '.';
				co++;
			}
		}
	}
	printf("%d\n", co);
	return 0;
}