// detail: https://atcoder.jp/contests/abc129/submissions/5846711
#include<stdio.h>
int main(void)
{
	int n;
	int w[100];
	int i, sum = 0, t, h = 0;
	int minsum=0, maxsum=0;
	int temp[100];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	t = n / 2;
	if (!(n % 2 == 0)) {
		t += 1;
	}
	while (t>0) {
		minsum = maxsum = 0;
		for (i = 0; i < t; i++) {
			minsum += w[i];
		}
		for (i = t; i < n; i++) {
			maxsum += w[i];
		}
		sum = minsum - maxsum;
		if (sum < 0) {
			sum *= -1;
		}
		temp[h++] = sum;
		for (i = 0; i < h; i++) {
			if (sum < temp[i]) {
				temp[i] = sum;
			}
		}
		t--;
	}
	t = n / 2;
	if (!(n % 2 == 0)) {
		t += 1;
	}
	while (t < n) {
		minsum = maxsum = 0;
		for (i = 0; i < t; i++) {
			minsum += w[i];
		}
		for (i = t; i < n; i++) {
			maxsum += w[i];
		}
		sum = minsum - maxsum;
		if (sum < 0) {
			sum *= -1;
		}
		temp[h++] = sum;
		for (i = 0; i < h; i++) {
			if (sum < temp[i]) {
				temp[i] = sum;
			}
		}
		t++;
	}
	for (i = 0; i < h; i++) {
		if (sum > temp[i]) {
			sum = temp[i];
		}
	}
	printf("%d\n", sum);
	return 0;
}