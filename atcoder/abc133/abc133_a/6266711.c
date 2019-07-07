// detail: https://atcoder.jp/contests/abc133/submissions/6266711
#include<stdio.h>
int main(void)
{
	int n;
	int a, b;

	scanf("%d", &n);
	scanf("%d %d", &a,&b);
	if (n*a > b) {
		printf("%d\n", b);
	}
	else {
		printf("%d\n", a*n);
	}
	return 0;
}