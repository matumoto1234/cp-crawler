// detail: https://atcoder.jp/contests/joi2016yo/submissions/7210568
#include<stdio.h>
typedef long long int ll;
int main(void)
{
	int n, m;
	char a[51][51];
	int cntw, cntb, cntr;
	ll min;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	
	min = 9999999999;
	for (int i = 1; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			cntw = cntb = cntr = 0;

			for (int ii = 0; ii < i; ii++) {
				for (int jj = 0; jj < m; jj++) {
					if (a[ii][jj] != 'W') {
						cntw++;
					}
				}
			}
			for (int ii = i; ii < j; ii++) {
				for (int jj = 0; jj < m; jj++) {
					if (a[ii][jj] != 'B') {
						cntb++;
					}
				}
			}
			for (int ii = j; ii < n; ii++) {
				for (int jj = 0; jj < m; jj++) {
					if (a[ii][jj] != 'R') {
						cntr++;
					}
				}
			}

			if (cntw + cntb + cntr < min) {
				min = cntw + cntb + cntr;
			}

		}
	}
	printf("%lld\n", min);
	return 0;
}