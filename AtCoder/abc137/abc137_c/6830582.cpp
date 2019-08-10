// detail: https://atcoder.jp/contests/abc137/submissions/6830582
#include<stdio.h>
#include<string.h>
int main(void)
{
	int n, i, j, k, h;
	int co, tempi = 0, flag;
	double ans = 0.0;
	static char a[200001][11], wk[200001][11];
	static int temp[2000001][2];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	for (i = 0; i < n; i++) {//調べるaの配列
		for (j = 0; j < n; j++) {//a[j]とa[i]を比較する
			if (i == j) {
				continue;
			}
			flag = 0;
			for (int ii = 0; ii < tempi; ii++) {
				if (temp[ii][0] == j && temp[ii][1] == i) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				continue;
			}
			strcpy(wk[j], a[j]);//wk[j]にa[j]を入れる
			co = 0;
			for (h = 0; a[i][h]!='\0'; h++) {
				//if (flag == 1)break;
				for (k = 0; wk[j][k]!='\0'; k++) {
					if (a[i][h] == wk[j][k]) {
						wk[j][k] = '0';
						co++;
					}
				}
			}
			if (co >= 10) {
				temp[tempi][0] = i;
				temp[tempi++][1] = j;
				//printf("%d %d %s\n", i, j, a[i]);
				ans++;
				/*for (int ii = 0; ii < 5; ii++) {
					sprintf(a[i], "%d%d", i, j);
				}*/
				//printf("a[i]=%s\n", a[i]);
			}
		}
	}
	printf("%.0lf\n", ans);
	return 0;
}