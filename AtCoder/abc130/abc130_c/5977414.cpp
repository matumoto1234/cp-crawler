// detail: https://atcoder.jp/contests/abc130/submissions/5977414
#include<stdio.h>
int main(void)
{
	int w, h, x, y;
	double menseki;
	int i, j, k;
	double x1, y1, w1, h1;

	scanf("%d %d %d %d", &w, &h, &x, &y);
	w1 = (double)w;
	h1 = (double)h;
	x1 = (double)x;
	y1 = (double)y;
	menseki = (double)w*(double)h;
	if (x == w / 2) {
		if (y == h / 2) {
			printf("%.9lf\n", menseki / 2);
			printf("1\n");
			return 0;
		}
	}
	if (x1 == w1 / 2 || y1 == h1 / 2) {
		printf("%.9lf\n", menseki / 2);
		printf("0\n");
	}
	else {
		if (w / 2 > x) {
			w =w - (w - x);
		}
		else {
			w = w - x;
		}
		menseki = w * h;
		printf("%.9lf\n", menseki);
		printf("1\n");
		
	}
	return 0;
}