// detail: https://atcoder.jp/contests/diverta2019/submissions/5345163
#include<stdio.h>
int main(void)
{
	int n, k;
	
	scanf("%d", &n);
	scanf("%d", &k);
	if (k > 1) {
		k = k - 1;
		n = n - k;
	}
	printf("%d\n", n);
	return 0;
}