// detail: https://atcoder.jp/contests/diverta2019-2/submissions/5918963
#include<stdio.h>
int main(void)
{
	int n;
	int k;
	int i;
	int sum=0;

	scanf("%d", &n);
	scanf("%d", &k);
	sum = n - k;
	sum = sum - 1;
	printf("%d\n", sum);

	return 0;
}