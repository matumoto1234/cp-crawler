// detail: https://atcoder.jp/contests/otemae2019/submissions/6648992
#include<stdio.h>
int main(void)
{
	int m, n, k;
	int x[2000];
	int i, j, temp, co, sum, max;

	scanf("%d %d %d", &m, &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	//ソート
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (x[i] > x[j]) {
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
	max = -1;
	for (i = 0; i < n - 1; i++) {
		co = 1;
		if (x[i] == x[i + 1]) {
			for (j = i + 1; x[i] == x[j]; j++) {
				co++;
			}
		}
		if (max < co) {
			max = co;
		}
	}
	co = max;
	sum = 0;
	for (i = 1; i <= k; i++) {
		sum += i;
		for (j = 0; j < n - 1; j++) {
			if (x[j + 1] - x[j] == sum) {
				co++;
				break;
			}
			else if (x[j + 1] - x[j] == i) {
				co++;
				break;
			}
		}
	}
	printf("%d\n", co);
	return 0;
}