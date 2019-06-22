// detail: https://atcoder.jp/contests/abc131/submissions/6068811
#include<stdio.h>
int main(void)
{
	long long int a, b, c, d;
	long long int i, j, k;
	long long int cnt = 0;
	int flag2, flag3, flag5;

	flag2 = flag3 = flag5 = 0;
	scanf("%lld", &a);
	scanf("%lld", &b);
	scanf("%lld", &c);
	scanf("%lld", &d);
	for (i = a; i <= b; i++) {
		if (i%c == 0) {
			continue;
		}
		else if (i%d == 0) {
			continue;
		}
		if (i%c != 0) {
			if (i%d != 0) {
				cnt++;
			}
		}
	}
	printf("%lld\n", cnt);
	return 0;
}