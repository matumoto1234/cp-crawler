// detail: https://atcoder.jp/contests/abc131/submissions/6073319
#include<stdio.h>
int main(void)
{
	long long int a, b, c, d;
	long long int i, j, k, l;
	long long int cnt = 0, oyoso = 1000;
	int plist[100], flag;

	k = 0;
	scanf("%lld", &a);
	scanf("%lld", &b);
	scanf("%lld", &c);
	scanf("%lld", &d);
	plist[k++] = 2;
	if (b >= 1000000) {
		oyoso = b / 1000000;
	}
	for (i = 1; i < oyoso; i+=2) {
		flag = 0;
		for (j = 2; j < i; j++) {
			for (l = 0; l < k; l++) {
				if (i%plist[l] == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				break;
			}
			if (i % j == 0) {
				flag = 1;
			}
		}
		if (flag == 1) {
			continue;
		}
		else {
			plist[k++] = i;
		}
	}
	for (i = a; i <= b; i++) {
		flag = 0;
		for (j = 0; j < k; j++) {
			if (i == plist[j]) {
				cnt++;
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
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