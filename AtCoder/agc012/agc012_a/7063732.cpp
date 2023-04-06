// detail: https://atcoder.jp/contests/agc012/submissions/7063732
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
int main(void)
{
	int n;
	static ll a[300000];
	static ll teem[100000][3];
	ll sum = 0;
	int teemi = 0;

	scanf("%d", &n);
	for (int i = 0; i < 3 * n; i++) {
		scanf("%lld", &a[i]);
	}

	qsort((void*)a, 3*n, sizeof(a[0]), int_sort);

	for (int i = 0; i < n; i++) {
		teem[i][0] = a[i];
		a[i] = -1;
	}
	for (int i = n; i < 2 * n; i++) {
		//teem[teemi][1] = a[i];
		//teem[teemi++][2] = a[i + n];
		sum += a[i];
	}
	/*
	for (int i = 0; i < n; i++) {
		sum += teem[i][1];
	}*/
	printf("%lld\n", sum);
	/*
	for (int i = 0; i < 3 * n; i++) {
		printf("%d\n", a[i]);
	}*/
	return 0;
}