// detail: https://atcoder.jp/contests/abc139/submissions/7275854
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int asc(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int desc(const void* a, const void* b) { return *(int*)b - *(int*)a; }

//qsort(data,10,sizeof(int),compare_int);

int main(void)
{
	int n;
	int h[100000];
	int start, max, cnt;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}

	max = cnt = 0;
	start = h[0];
	for (int i = 1; i < n; i++) {
		
		if (start >= h[i]) {
			cnt++;
			if (i == n - 1) {
				if (max < cnt) {
					max = cnt;
				}
			}
			start = h[i];
		}
		else if (start < h[i]) {
			//printf("%d\n", h[i]);
			if (max < cnt) {
				max = cnt;
				cnt = 0;
			}
			cnt = 0;
			start = h[i];
		}
		//printf("start?%d\n", start);
	}
	printf("%d\n", max);
	return 0;
}