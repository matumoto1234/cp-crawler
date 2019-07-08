// detail: https://atcoder.jp/contests/joi2007yo/submissions/6310747
#include<stdio.h>
int main(void)
{
	int a[28];
	int i;
	int s[30];

	for (i = 0; i < 28; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 28; i++) {
		s[a[i]-1] = a[i];
	}
	for (i = 1; i <= 30; i++) {
		if (s[i-1] != i) {
			printf("%d\n", i);
		}
	}
	return 0;
}