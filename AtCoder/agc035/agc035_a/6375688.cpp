// detail: https://atcoder.jp/contests/agc035/submissions/6375688
#include<stdio.h>
int main(void) {
	int n, i, j, k;
	int a[100000];
	int flag = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int sum;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			sum = a[i] ^ a[j];
			for (k = 0; k < n; k++) {
				if (a[k] == a[i] || a[k] == a[j]) {
					continue;
				}
				if (sum != a[k]) {
					flag = 1;
					goto end;
				}
			}
		}
	}
	end:
	if (flag == 0) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}