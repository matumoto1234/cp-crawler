// detail: https://atcoder.jp/contests/joi2010yo/submissions/6749679
#include<stdio.h>
int main(void)
{
	int n, m, h, i, j;
	static int a[100000], b[100000], fr[100000], fr2[100000];
	int fri = 0, fri2 = 0;
	int flag;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	/*まずは友達を探す*/
	for (i = 0; i < m; i++) {
		if (a[i] == 1) {
			fr[fri++] = b[i];
		}
	}
	/*友達の友達を探す*/
	for (h = 0; h < m; h++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < fri; j++) {
				if (a[i] == fr[j]) {
					flag = 0;
					for (int k = 0; k < fri; k++) {
						if (b[i] == fr[k]) {
							flag = 1;
							break;
						}
					}
					for (int k = 0; k < fri2; k++) {
						if (b[i] == fr2[k]) {
							flag = 1;
							break;
						}
					}
					if (flag == 0) {
						fr2[fri2++] = b[i];
					}
				}
			}
		}
	}
	for (i = 0; i < fri; i++) {
		printf("%d\n", fr[i]);
	}
	for (i = 0; i < fri2; i++) {
		printf("%d\n", fr2[i]);
	}
	printf("\n%d\n", fri + fri2);
	return 0;
}
