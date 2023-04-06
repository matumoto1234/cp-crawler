// detail: https://atcoder.jp/contests/joi2015yo/submissions/6514538
#include<stdio.h>
int main(void)
{
	int h, w;
	int i, j, k;
	char a[101][101];
	int b[101][101];
	int temp[101][101] = { 0 };

	scanf("%d %d", &h, &w);
	for (i = 0; i < h; i++) {
		scanf("%s", a[i]);
	}
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (a[i][j] == 'c') {
				b[i][j] = 0;
				temp[i][j] = 1;
				for (k = 1; k + j < w; k++) {
					if (a[i][k + j] == '.') {
						b[i][k + j] = k;
						temp[i][k + j] = 1;
					}
				}
			}
		}
	}
	printf("\n");
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (temp[i][j] == 0) {
				b[i][j] = -1;
			}
		}
	}
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			printf("%d", b[i][j]);
		}
	}
	printf("\n");
	return 0;
}