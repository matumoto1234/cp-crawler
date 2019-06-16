// detail: https://atcoder.jp/contests/abc130/submissions/5966475
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
			printf("%lf\n", menseki / 2);
			printf("1\n");
			return 0;
		}
	}
	if (x == w / 2 || y == h / 2) {
		printf("%lf\n", menseki/2);
		printf("0");
	}
	return 0;
}