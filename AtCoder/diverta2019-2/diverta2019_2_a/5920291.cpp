// detail: https://atcoder.jp/contests/diverta2019-2/submissions/5920291
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

	if (k == 1) {
		sum = 0;
	}
	printf("%d\n", sum);

	return 0;
}