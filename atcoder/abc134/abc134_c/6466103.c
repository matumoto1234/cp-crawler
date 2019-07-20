// detail: https://atcoder.jp/contests/abc134/submissions/6466103
#include<stdio.h>
int main(void)
{
	int n, max = -1;
	int i;
	int a[200000];
	int maxlist[2] = { 0 };
	int j, maxi = 0, k, flag, up = 0, kaku=-1;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 2; i++) {
		max = 0;
		for (j = 0; j < n; j++) {
			if (kaku == j) {
				continue;
			}
			if (max < a[j]) {
				max = a[j];
			}
		}
		if (maxi < 2) {
			maxlist[maxi++] = max;
			for (k = 0; k < n; k++) {
				if (a[k] == max) {
					kaku = k;
					break;
				}
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (maxlist[0] != a[i]) {
			printf("%d\n", maxlist[0]);
		}
		else {
			printf("%d\n", maxlist[1]);
		}
	}
	return 0;
}