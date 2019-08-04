// detail: https://atcoder.jp/contests/abc136/submissions/6714058
#include<stdio.h>
int main(void)
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	int sa;
	sa = a - b;
	c -= sa;
	if (c < 0) {
		printf("0\n");
	}
	else {
		printf("%d\n", c);
	}
	return 0;
}