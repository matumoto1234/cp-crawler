// detail: https://atcoder.jp/contests/joi2017yo/submissions/6527456
#include<stdio.h>
int main(void)
{
	int n, m, d, i, j, k;
	char a[101][101];
	int flag, co;

	scanf("%d %d %d", &n, &m, &d);
	for (i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	co = 0;
	/*横*/
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			flag = 0;
			if (a[i][j] == '.') {
				for (k = 0; k < d && j + k < m; k++) {
					if (a[i][j+k] == '.'&& k == d-1) {
						flag = 1;
					}
					else if (a[i][j + k] != '.') {
						break;
					}
				}
				if (flag == 1) {
					co++;
				}
			}
		}
	}
	/*縦*/
	for (j = 0; j < m; j++) {
		for (i = 0; i < n; i++) {
			flag = 0;
			if (a[i][j] == '.') {
				for (k = 0; k < d &&i + k < n; k++) {
					if (a[i + k][j] == '.'&& k == d-1) {
						flag = 1;
					}
					else if (a[i + k][j] != '.') {
						break;
					}
				}
				if (flag == 1) {
					co++;
				}
			}
		}
	}
	printf("%d\n", co);
	return 0;
}