// detail: https://atcoder.jp/contests/abc117/submissions/4163509
#include<stdio.h>
int main(void)
{
	int b,c,i,max;
	scanf("%d", &b);
	int a[10];
	for (i = 0; i<b; i++) {
		scanf("%d", &a[i]);
		c = c + a[i];
		if (max < a[i]) {
			max = a[i];
		}
	}
	if (max < c) {
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}