// detail: https://atcoder.jp/contests/exawizards2019/submissions/4772249
#include<stdio.h>
int main(void)
{
	int n,q;
	char s[10000],temp[10000];
	int i, j, co = 0;
	char t[10000], d[10000];
	
	scanf("%d", &n);
	scanf("%d", &q);
	scanf("%s", s);
	for (i = 0; i < n; i++) {
		temp[i] = 'G';
	}
	for (i = 0; i < q; i++) {
		
		scanf("%*c%c", &t[i]);
		scanf("%*c%c", &d[i]);
		for (j = 0; s[j] != '\0'; j++) {
			if (t[i] == s[j]) {
				if (d[i] == 'L') {
					if (j != 0) {
						temp[j - 1] = 'G';
					}
					temp[j] = '0';
				}
				else if (d[i] == 'R') {
					if (j != n) {
						temp[j + 1] = 'G';
					}
					temp[j] = '0';
				}
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (temp[i] == 'G') {
			co++;
		}
	}
	printf("%d\n", co);
	return 0;
}