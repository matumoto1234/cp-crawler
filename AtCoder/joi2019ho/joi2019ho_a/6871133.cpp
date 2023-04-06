// detail: https://atcoder.jp/contests/joi2019ho/submissions/6871133
#include<stdio.h>
#include<string.h>
int main(void)
{
	int h, w, i, j;
	static char a[3001][3001];
	int ob, in, ans = 0;

	scanf("%d %d", &h, &w);
	for (i = 0; i < h; i++) {
		scanf("%s", a[i]);
	}
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			ob = in = 0;
			if (a[i][j] == 'J') {
				for (int k = j+1; k < w; k++) {
					if (a[i][k] == 'O') {
						ob++;
					}
				}
				for (int k = i+1; k < h; k++) {
					if (a[k][j] == 'I') {
						in++;
					}
				}
				ans += ob * in;
				/*if (ob > 0 && in > 0) {
					printf("i>%d j>%d\n", i, j);
					printf("ob>%d in>%d\n", ob, in);
				}*/
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}