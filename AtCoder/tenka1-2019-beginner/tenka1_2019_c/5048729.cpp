// detail: https://atcoder.jp/contests/tenka1-2019-beginner/submissions/5048729
#include<stdio.h>
int main(void)
{
	int n;
	int i, co = 0;
	char a[200001];

	scanf("%d", &n);
	scanf("%s", a);
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] == '.') {
			if (a[i - 1] == '#') {
				a[i - 1] = '.';
				co++;
			}
		}
		else if (a[i] == '#') {
			if (a[i + 1] == '.') {
				a[i + 1] = '#';
				co++;
			}
		}
	}
	printf("%d\n", co);
	return 0;
}