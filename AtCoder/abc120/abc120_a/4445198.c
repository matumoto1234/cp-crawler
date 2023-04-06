// detail: https://atcoder.jp/contests/abc120/submissions/4445198
#include<stdio.h>
int main(void)
{
	int a, b, c,co=0;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	while (a > b||c!=0) {
		b = b - a;
		co++;
		c--;
	}
	printf("%d\n",co);
	return 0;
}