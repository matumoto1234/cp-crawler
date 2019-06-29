// detail: https://atcoder.jp/contests/abc132/submissions/6186492
#include<stdio.h>
int main(void)
{
	int i;
	char s[100];
	char a1, a2;
	int flag = 0, co = 0, co2 = 0;

	scanf("%s", s);
	a1 = s[0];
	a2 = '0';
	for (i = 0; s[i] != '\0'; i++) {
		if (a1 == s[i]) {
			co++;
			if (co >= 3) {
				flag = 1;
			}
		}
		else if (a2 == s[i]) {
			co2++;
			if (co2 >= 3) {
				flag = 1;
			}
		}
		else if (a1 != s[i]) {
			if (a2 == '0') {
				a2 = s[i];
			}
			else {
				flag = 1;
			}
		}
	}
	if (flag == 0) {
		printf("Yes\n");
	}
	else if (flag == 1) {
		printf("No\n");
	}
	return 0;
}