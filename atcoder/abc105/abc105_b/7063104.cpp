// detail: https://atcoder.jp/contests/abc105/submissions/7063104
#include<stdio.h>
int main(void)
{
	int n;
	int si,na;
	int flag = 0;

	si = na = 0;
	scanf("%d", &n);
	for (int i = 0; i < 100; i++) {
		na = 0;
		si += 4;
		for (int j = 0; j < 100; j++) {
			na += 7;
			if (n == si || n == na || n == si + na) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)break;
	}
	if (flag == 1) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}