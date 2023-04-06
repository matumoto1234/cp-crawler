// detail: https://atcoder.jp/contests/joi2014yo/submissions/6514178
#include<stdio.h>
int main(void)
{
	int n, m;
	int a[1000], b[1000];
	int rank[1000] = { 0 };
	int i, j, k, max, maxi;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (a[j] <= b[i]) {
				rank[j]++;
				break;
			}
		}
	}
	max = -1;
	
	for (i = 0; i < n; i++) {
		if (max < rank[i]) {
			max = rank[i];
			maxi = i;
		}
	}
	printf("%d\n", maxi+1);
	return 0;
}