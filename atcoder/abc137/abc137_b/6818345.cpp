// detail: https://atcoder.jp/contests/abc137/submissions/6818345
#include<stdio.h>
int main(void)
{
	int k, x, i, j;

	scanf("%d %d", &k, &x);
	for (i = x-k+1; i < x+k; i++) {
		printf("%d ", i);
	}
	return 0;
}