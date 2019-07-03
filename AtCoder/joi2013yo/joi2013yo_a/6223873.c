// detail: https://atcoder.jp/contests/joi2013yo/submissions/6223873
#include<stdio.h>
int main(void)
{
	int l,a, b, c, d;
	int maco, jaco;

	maco = jaco = 0;
	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
	while (a > 0) {
		jaco++;
		a -= c;
	}
	while (b > 0) {
		maco++;
		b -= d;
	}
	if (maco > jaco) {
		l = l - maco;
	}
	else {
		l = l - jaco;
	}
	printf("%d\n", l);
	return 0;
}