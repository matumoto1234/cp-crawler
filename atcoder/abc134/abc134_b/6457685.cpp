// detail: https://atcoder.jp/contests/abc134/submissions/6457685
#include<stdio.h>
int main(void)
{
	int n,d;
	int i;
	int temp, co = 0;

	scanf("%d %d",&n,&d);
	while (n > 0) {
		temp = d + 1;
		temp = temp + d;
		n -= temp;
		co++;
	}
	printf("%d\n", co);
	return 0;
}