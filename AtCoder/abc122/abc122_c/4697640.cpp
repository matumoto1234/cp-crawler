// detail: https://atcoder.jp/contests/abc122/submissions/4697640
#include<stdio.h>
int main(void)
{
	int n,q,l[100000],r[1000000];
	char s[100000];
	int i,co,temp;

	co = 0;
	scanf("%d", &n);
	scanf("%d", &q);
	scanf("%s",s);
	for (i = 0; i < n; i++) {
		scanf("%d", &l[i]);
		scanf("%d", &r[i]);
	}
	for (i = 0; i < n; i++) {
		while (s[l[i]] < s[r[i]]) {
			switch (s[l[i]]) {
			case 'A':
				temp = l[i] + 1;
				if (s[temp] = 'C') {
					co++;
				}
			}
			l[i]++;
		}
		printf("%d\n", co);
	}
	return 0;
}