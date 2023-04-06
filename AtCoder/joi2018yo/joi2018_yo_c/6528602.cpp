// detail: https://atcoder.jp/contests/joi2018yo/submissions/6528602
#include<stdio.h>
int main(void)
{
	int h, w, i, j, k;
	int a[100][100];
	int tempx, tempy, sum, min;

	scanf("%d %d", &h, &w);
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	min = 9999999999;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {

			sum = 0;
			for (int i2 = 0; i2 < h; i2++) {
				for (int j2 = 0; j2 < w; j2++) {
					if (i == i2 || j == j2) {
						continue;
					}
					tempx = i2 - i;
					tempy = j2 - j;
					if (tempx < 0) {
						tempx *= -1;
					}
					if (tempy < 0) {
						tempy *= -1;
					}
					if (tempx < tempy) {
						tempx *= a[i2][j2];
						sum += tempx;
					}
					else {
						tempy *= a[i2][j2];
						sum += tempy;
					}
				}
			}
			if (min > sum) {
				min = sum;
			}

		}
	}
	printf("%d\n", min);
}