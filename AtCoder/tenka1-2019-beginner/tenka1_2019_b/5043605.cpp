// detail: https://atcoder.jp/contests/tenka1-2019-beginner/submissions/5043605
#include<stdio.h>
int main(void)
{
	int n, k;
	char s[11];
	int i;

	scanf("%d", &n);
	scanf("%s", s);
	scanf("%d", &k);
	for (i = 0; s[i] != '\0'; i++) {
		if (s[k-1] != s[i]) {
			s[i] = '*';
		}
	}
	printf("%s\n", s);
	return 0;
}