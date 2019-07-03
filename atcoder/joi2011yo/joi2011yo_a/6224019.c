// detail: https://atcoder.jp/contests/joi2011yo/submissions/6224019
#include<stdio.h>
int main(void)
{
	int a, b, c, d;
	int jikan, mi, se;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	jikan = a + b + c + d;
	if (jikan >= 60) {
		mi = jikan / 60;
	}
	se = jikan % 60;
	printf("%d\n%d\n", mi, se);
	return 0;
}