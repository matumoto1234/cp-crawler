// detail: https://atcoder.jp/contests/abc124/submissions/4956863
#include<stdio.h>
int main(void)
{
	char a[100001];
	int i, co = 0;

	scanf("%s", a);
	
	for (i = 0; a[i] != '\0'; i++) {
		switch (a[i]) {
		case '0':
			if (a[i - 1] == '0') {
				a[i] = '1';
				co++;
			}
			break;
		case '1':
			if (a[i - 1] == '1') {
				a[i] = '0';
				co++;
			}
			break;
		}
	}
	printf("%d\n",co);
	return 0;
}