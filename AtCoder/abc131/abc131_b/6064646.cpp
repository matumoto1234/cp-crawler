// detail: https://atcoder.jp/contests/abc131/submissions/6064646
#include<stdio.h>
int main(void)
{
	int n,l;
	int taste[200];
	int i, min, j;
	int temp, wa1, wa2;
	int k[200];

	min = wa1 = wa2 = 0;
	scanf("%d", &n);
	scanf("%d", &l);
	for (i = 1; i <= n; i++) {
		taste[i-1] = i + l - 1;
	}
	for (i = 0; i < n; i++) {
		k[i] = taste[i];
		if (k[i] < 0) {
			k[i] *= -1;
		}
	}
	for (i = 0; i < n - 1; i++) {
		for (j = i; j < n; j++) {
			if (k[i] > k[j]) {
				temp = k[i];
				k[i] = k[j];
				k[j] = temp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		wa1 += taste[i];
		wa2 += taste[i];
	}
	if (wa2 >= 0) {
		wa2 -= k[0];
	}
	else {
		wa2 += k[0];
	}
	printf("%d\n", wa2);
	return 0;
}