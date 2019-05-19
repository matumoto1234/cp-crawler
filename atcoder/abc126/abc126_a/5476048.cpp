// detail: https://atcoder.jp/contests/abc126/submissions/5476048
#include<stdio.h>
int main(void)
{
	int n, k;
	char s[51];

	scanf("%d", &n);
	scanf("%d", &k);
	scanf("%s", s);
	switch (s[k - 1]) {
	case 'A':
		s[k - 1] = 'a';
		break;
	case 'B':
		s[k - 1] = 'b';
		break;
	case 'C':
		s[k - 1] = 'c';
		break;
	}
	printf("%s\n", s);
	return 0;
}