// detail: https://atcoder.jp/contests/diverta2019-2/submissions/5933096
#include<stdio.h>
int main(void)
{
	int n;
	long int x[100], y[100];
	int i, j;
	int xmax,ymax;
	long int xtemp[100], ytemp[100];
	int temp, co,xco,yco,xatai,yatai;
	int cost, flag;

	xmax = ymax = co = xco = yco = xatai = yatai = 0;
	cost = flag = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%ld %ld", &x[i], &y[i]);
	}
	
	for (i = 0; i < n - 1; i++) {
		for (j = i; j < n; j++) {
			if (x[i] < x[j]) {
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
			if (y[i] < y[j]) {
				temp = y[i];
				y[i] = y[j];
				y[j] = temp;
			}
		}
	}
	
	for (i = 0; i < n-1; i++) {
		xtemp[i] = x[i] - x[i + 1];
		ytemp[i] = y[i] - y[i + 1];
	}
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (xtemp[i] == xtemp[j]) {
				if (i == j) {
					continue;
				}
				temp = xtemp[i];
				co++;
			}
		}
		if (xco < co) {
			xco = co;
			xatai = temp;
			flag = 1;
		}
	}
	if (flag == 0) {
		xco = co;
		xatai = temp;
	}
	flag = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (ytemp[i] == ytemp[j]) {
				if (i == j) {
					continue;
				}
				temp = ytemp[i];
				co++;
			}
		}
		if (yco < co) {
			yco = co;
			yatai = temp;
			flag = 1;
		}
	}
	if (flag == 0) {
		yco = co;
		yatai = temp;
	}
	for (i = 0; i < n; i++) {
		if (x[i] - x[i + 1] == xatai) {
			if (y[i] - y[i + 1] == yatai) {
				continue;
			}
		}
		cost++;
	}
	printf("%d\n", cost);
	return 0;
}