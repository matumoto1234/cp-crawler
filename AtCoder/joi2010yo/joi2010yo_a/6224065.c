// detail: https://atcoder.jp/contests/joi2010yo/submissions/6224065
#include<stdio.h>
int main(void)
{
	int a, b, c, d, e, f, g, h, i, j;

	scanf("%d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
	a -= b;
	a -= c;
	a -= d;
	a -= e;
	a -= f;
	a -= g;
	a -= h;
	a -= i;
	a -= j;
	printf("%d\n", a);
	return 0;
}