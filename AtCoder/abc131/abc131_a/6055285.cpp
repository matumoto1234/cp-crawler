// detail: https://atcoder.jp/contests/abc131/submissions/6055285
#include<stdio.h>
int main(void)
{
	int i, j;
	char s[5];

	scanf("%s", s);
	for (i = 0; i < 3; i++) {
		j = i + 1;
		if (s[i] == s[j]) {
			printf("Bad\n");
			return 0;
		}
	}
	printf("Good\n");
	return 0;
}