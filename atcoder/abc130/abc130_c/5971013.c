// detail: https://atcoder.jp/contests/abc130/submissions/5971013
#include<stdio.h>
int main(void)
{
	int w, h, x, y;
	double menseki;
	int i, j, k;

	scanf("%d %d %d %d", &w, &h, &x, &y);
	menseki = (double)w*(double)h;
	if (x == w / 2) {
		if (y == h / 2) {
			printf("%.9lf\n", menseki / 2);
			printf("1\n");
			return 0;
		}
	}
	if (x == w / 2 || y == h / 2) {
		printf("%.9lf\n", menseki / 2);
		printf("0\n");
	}
	else {
		if (w / 2 < x) {
			w = w - x;
		}
		else {
			w = w - (w - x);
		}
		menseki = w * h;
		printf("%.9lf\n", menseki);
		printf("1\n");
	}
	return 0;
}