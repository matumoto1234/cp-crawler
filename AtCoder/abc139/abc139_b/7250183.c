// detail: https://atcoder.jp/contests/abc139/submissions/7250183
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
int asc(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int desc(const void* a, const void* b) { return *(int*)b - *(int*)a; }

//qsort(data,10,sizeof(int),compare_int);

int main(void)
{
	int a, b;
	int sum = 1;
	int i = 0;

	scanf("%d %d", &a, &b);
	while (sum < b) {
		i++;
		sum--;
		sum += a;
	}
	printf("%d\n", i);
	return 0;
}