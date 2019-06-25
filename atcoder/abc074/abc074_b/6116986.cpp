// detail: https://atcoder.jp/contests/abc074/submissions/6116986
#include<stdio.h>
int main(void)
{
	int n, k;
	int s[100];
	int i;
	int sum = 0;

	scanf("%d", &n);
	scanf("%d", &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	for (i = 0; i < n; i++) {
		if (s[i] > k / 2) {
			sum += (k - s[i]) * 2;
		}
		else {
			sum += s[i] * 2;
		}
	}
	printf("%d\n", sum);
	return 0;
}