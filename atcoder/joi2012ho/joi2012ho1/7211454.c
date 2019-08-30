// detail: https://atcoder.jp/contests/joi2012ho/submissions/7211454
#include<stdio.h>
#include<string.h>
typedef long long int ll;
int main(void)
{
	static char s[1000001];
	int len, cntj, cnto, cnti;
	ll max = 0;

	scanf("%s", s);
	len = strlen(s);
	for (int i = 0; i < len; i++) {
		
		if (s[i] == 'O') {
			cntj = cnto = cnti = 0;

			for (int j = i; s[j] == 'O'; j++) {
				s[j] = 'x';
				cnto++;
			}
			for (int j = i + cnto; s[j] == 'I'; j++) {
				cnti++;
			}
			for (int j = i - 1; s[j] == 'J'; j--) {
				cntj++;
			}
			//printf("j>%d o>%d i>%d\n", cntj, cnto, cnti);
			if (cnto <= cntj && cnto <= cnti) {
				if (max < cnto) {
					max = cnto;
				}
			}
		}

	}
	printf("%lld\n", max);
	return 0;
}