// detail: https://atcoder.jp/contests/abc139/submissions/7247006
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
int asc(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int desc(const void* a, const void* b) { return *(int*)b - *(int*)a; }

//qsort(data,10,sizeof(int),compare_int);

int main(void)
{
	char s[200001];
	char t[4];

	scanf("%s %s", s, t);
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (s[i] == t[i])cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}