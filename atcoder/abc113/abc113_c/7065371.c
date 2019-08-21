// detail: https://atcoder.jp/contests/abc113/submissions/7065371
#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;

int int_sort(const void* a, const void* b) {
	if (*(int*)a < *(int*)b) {
		return -1;
	}
	else
		if (*(int*)a == *(int*)b) {
			return 0;
		}
	return 1;
}
//qsort((void*)a, 3*n, sizeof(a[0]), int_sort);
#define NUM 100000
#define NUM_RANK 10000
int main(void)
{
	int n, m;
	int year[NUM], p[NUM];
	int rank[NUM][NUM_RANK+2] = {};

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &p[i], &year[i]);
	}
	for (long int i = 0; i < NUM; i++) {
		rank[i][NUM_RANK] = 1;
	}
	for (int i = 0; i < m; i++) {
		rank[p[i] - 1][year[i]]++;
	}
	for (long int j = 0; j < NUM; j++) {
		for (long int i = NUM_RANK; i >= 0; i--) {
			rank[j][i] += rank[j][i + 1];
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%06d%06d\n", p[i], rank[p[i]-1][year[i]]);
	}
	return 0;
}