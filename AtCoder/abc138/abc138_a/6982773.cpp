// detail: https://atcoder.jp/contests/abc138/submissions/6982773
#include<stdio.h>
#include<string.h>

int max(int x, int y) {
	if (x > y) return x;
	else return y;
}
int min(int x, int y) {
	if (x > y) return y;
	else return x;
}

int main(void)
{
	int a;
	char s[100001];

	scanf("%d %s", &a, s);
	if (a >= 3200) {
		printf("%s\n",s);
	}
	else {
		printf("red\n");
	}
	return 0;
}