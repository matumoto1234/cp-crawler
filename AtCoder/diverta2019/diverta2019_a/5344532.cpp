// detail: https://atcoder.jp/contests/diverta2019/submissions/5344532
#include<stdio.h>
int main(void)
{
	int n, k;
	int temp;
	
	scanf("%d", &n);
	scanf("%d", &k);
	if (k == 1) {

	}
	else if (k > 1) {
		k = k - 1;
		temp = n - k;
	}
	printf("%d\n", temp);
	return 0;
}