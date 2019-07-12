// detail: https://atcoder.jp/contests/joi2007yo/submissions/6349834
#include<stdio.h>
int main(void)
{
	int n, m, i, j;
	int k[1000], s[200];
	int a[200], b[200], c;
	int temp[200];

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &k[i]);
	}
	for(i = 0; i < 2 * n; i++) {
		s[i] = i + 1;
	}
	for (i = 0; i < m; i++) {
		if (k[i] == 0) {//リフルシャッフル
			c = 0;
			for (j = 0; j < n; j++) {//半分分け
				a[j] = s[j];
				b[j] = s[j + n];
			}
			
			for (j = 0; j < n; j++) {//一枚ずつ入れてる
				s[c++] = a[j];
				s[c++] = b[j];
			}
		}
		else {
			for (j = 0; j < k[i]; j++) {
				a[j] = s[j];
			}
			int bi = 0;
			for (j = k[i]; j < 2 * n; j++) {
				b[bi++] = s[j];
			}
			/*printf(">>A\n");
			for (j = 0; j < k[i]; j++) {
				printf("%d\n", a[j]);
			}
			printf(">>B\n");
			for (j = 0; j < 2*n-k[i]; j++) {
				printf("%d\n", b[j]);
			}*/
			int si = 0;
			for	(j = 0; j < 2 * n - k[i]; j++) {
				s[si++] = b[j];
			}
			for (j = 0; j < k[i]; j++) {
				s[si++] = a[j];
			}
			/*
			printf(">>S\n");
			for (j = 0; j < 2 * n; j++) {
				printf("%d\n", s[j]);
			}*/

			int bi2 = 0;
			for (j = 0; j < k[i]; j++) {
				if (bi2 > bi) {
					break;
				}
				s[j] = b[bi2++];
			}
			/*for (j = bi2; j < 2 * n; j++) {
				s[j]=a[]
			}*/
		}
	}
	for (i = 0; i < 2 * n; i++) {
		printf("%d\n", s[i]);
	}
	return 0;
}
