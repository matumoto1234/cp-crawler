// detail: https://atcoder.jp/contests/joi2012yo/submissions/6223959
#include<stdio.h>
int main(void)
{
	int pa1, pa2, pa3, ju1, ju2;
	int minpa;

	scanf("%d %d %d %d %d", &pa1, &pa2, &pa3, &ju1, &ju2);
	minpa = pa1;
	if (minpa > pa2) {
		minpa = pa2;
	}
	if (minpa > pa3) {
		minpa = pa3;
	}
	if (ju1 > ju2) {
		printf("%d\n", minpa + ju2 - 50);
	}
	else {
		printf("%d\n", minpa + ju1 - 50);
	}
	return 0;
}