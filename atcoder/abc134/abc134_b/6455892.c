// detail: https://atcoder.jp/contests/abc134/submissions/6455892
#include<stdio.h>
int main(void)
{
	int n;
	int i;

	scanf("%d %d",&n,&i);

	i = i * 2;
	if (n %(i+1)==0) {
		printf("%d\n", n / i);
	}
	else {
		printf("%d\n", n / i + 1);
	}

	return 0;
}