// detail: https://atcoder.jp/contests/tenka1-2019-beginner/submissions/5038618
#include<stdio.h>
int main(void)
{
	int a, b, c;
	int i;
	int flag = 0;
	
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	if (a > b) {
		for (i = a; i > b; i--) {
			if (i == c) {
				flag = 1;
			}
			
		}
	}
	else {
		for (i = b; i != a; i--) {
			if (i == c) {
				flag = 1;
			}
		}
	}
	if (flag == 1) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}