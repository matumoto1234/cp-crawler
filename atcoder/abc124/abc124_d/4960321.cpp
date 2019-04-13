// detail: https://atcoder.jp/contests/abc124/submissions/4960321
#include<stdio.h>
int main(void)
{
	int n, k;
	char a[100001];
	int i, j;
	int zeroco, temp, h, co;
	int maxzero[100000];

	zeroco = h = co = maxzero[0] = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	scanf("%s", a);
	for (j = 0; j < k; j++) {
		for (i = 0; a[i] != '\0'; i++) {
			if (a[i] == '0') {
				if (a[i - 1] != '1') {
					zeroco++;
				}
			}
			else {
				if (zeroco > maxzero[h]) {
					maxzero[h] = zeroco;
					zeroco = 0;
					temp = i - 1;
				}
			}
		}
		for (i = temp - maxzero[h]; a[i] < a[temp]; i++) {
			a[i] = '1';
		}
	}
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] == '1') {
			if (a[i - 1] != '0') {
				co++;
			}
		}
	}
	printf("%d\n", co);
	return 0;
}