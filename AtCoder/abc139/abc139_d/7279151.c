// detail: https://atcoder.jp/contests/abc139/submissions/7279151
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int asc(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int desc(const void* a, const void* b) { return *(int*)b - *(int*)a; }

//qsort(data,10,sizeof(int),compare_int);

int main(void)
{
	int n;
	long long int sum;

	scanf("%d", &n);
	sum = 0;
	for (int i = 1; i < n; i++) {
		sum += i;
	}
	printf("%lld\n", sum);
	return 0;
}