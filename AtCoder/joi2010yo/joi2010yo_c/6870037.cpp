// detail: https://atcoder.jp/contests/joi2010yo/submissions/6870037
#include<stdio.h>
int main(void)
{
	int n, m, i, j;
	int a[10000], b[10000];
	int fr1[10000], fr2[100000];

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	int fri = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == 1) {
			fr1[fri++] = b[i];
		}
		else if (b[i] == 1) {
			fr1[fri++] = a[i];
		}
	}
	int fri2 = 0, flag;
	for (i = 0; i < n; i++) {
		for (j = 0; j < fri; j++) {
			if (a[i] == fr1[j]) {
				if (b[i] == 1) {
					continue;
				}
				flag = 0;
				for (int k = 0; k < fri; k++) {
					if (fr1[k] == b[i]) {
						flag = 1;
					}
				}
				for (int k = 0; k < fri2; k++) {
					if (fr2[k] == b[i]) {
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					continue;
				}
				fr2[fri2++] = b[i];
			}
			else if (b[i] == fr1[j]) {
				if (a[i] == 1) {
					continue;
				}
				flag = 0;
				for (int k = 0; k < fri; k++) {
					if (fr1[k] == a[i]) {
						flag = 1;
					}
				}
				for (int k = 0; k < fri2; k++) {
					if (fr2[k] == a[i]) {
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					continue;
				}
				fr2[fri2++] = a[i];
			}
		}
	}
	printf("%d\n", fri+fri2);
	return 0;
}