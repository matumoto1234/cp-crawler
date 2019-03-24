// detail: https://atcoder.jp/contests/abc122/submissions/4687773
#include<stdio.h>
int main(void)
{
	char b;
	scanf("%c", &b);
	switch (b) {
	case 'A':
		printf("T\n");
		break;
	case 'T':
		printf("A\n");
		break;
	case 'C':
		printf("G\n");
		break;
	case 'G':
		printf("C\n");
		break;
	}
	return 0;
}