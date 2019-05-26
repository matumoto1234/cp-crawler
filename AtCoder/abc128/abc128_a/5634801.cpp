// detail: https://atcoder.jp/contests/abc128/submissions/5634801
#include<stdio.h>
int main(void)
{
	int a, p;
	int pie;

	scanf("%d", &a);
	scanf("%d", &p);

	pie = a * 3;
	pie = pie + p;
	pie = pie / 2;
	printf("%d\n", pie);
	return 0;
}