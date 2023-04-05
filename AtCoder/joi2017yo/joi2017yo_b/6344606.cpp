// detail: https://atcoder.jp/contests/joi2017yo/submissions/6344606
#include<stdio.h>
int main(void)
{
	int n, m, i, j, co;
	int a[2000], b[2000];
	int temp, money;

	co = money = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (i = 0; i < m; i++) {
		if (a[i] >= n) {
			co++;
		}
	}
	if (co < m-1) {
		for (i = 0; i < n - 1; i++) {
			for (j = i + 1; j < n; j++) {
				if (a[i] < a[j]) {
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
		/*for (i = 0; i < m; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");*/
		for (i = 0; i < m; i++) {
			if (co >= m - 1) {
				break;
			}
			if (a[i] < n) {
				while (a[i] < n) {
					a[i]++;
					money++;
				}
				co++;
			}
		}
		printf("%d\n", money);
	}
	else {
		printf("0\n");
	}
	return 0;
}