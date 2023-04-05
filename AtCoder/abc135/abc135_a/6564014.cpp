// detail: https://atcoder.jp/contests/abc135/submissions/6564014
#include<stdio.h>
int main(void)
{
	int a,b;
	int i;
	int temp, temp1, flag = 0;

	scanf("%d %d", &a,&b);
	if (a > b) {
		for (i = 0; i < a ; i++) {
			temp = a - i;
			if (temp < 0) {
				temp *= -1;
			}
			temp1 = i - b;
			if (temp1 < 0)temp1 *= -1;
			if (temp == temp1) {
				flag = 1;
				break;
			}
		}
	}
	else {
		for (i = 0; i < b ; i++) {
			temp = a - i;
			if (temp < 0) {
				temp *= -1;
			}
			temp1 = i - b;
			if (temp1 < 0)temp1 *= -1;
			if (temp == temp1) {
				flag = 1;
				break;
			}
		}
	}

	if (flag == 1) {
		printf("%d\n", i);
	}
	else {
		printf("IMPOSSIBLE\n");
	}
	return 0;
}