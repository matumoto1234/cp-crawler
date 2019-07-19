// detail: https://atcoder.jp/contests/joisc2007/submissions/6431440
#include<stdio.h>
int main(void)
{
	int n;
	int a[100000], i, j;
	int rank[100000];

	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		rank[i] = 1;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (a[i] < a[j]) {
				rank[i]++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d\n", rank[i]);
	}
	return 0;
}