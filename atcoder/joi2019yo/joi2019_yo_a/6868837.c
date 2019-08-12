// detail: https://atcoder.jp/contests/joi2019yo/submissions/6868837
#include<stdio.h>
int main(void)
{
	int a, b, c;
	int co = 0, sum = 0;
	int day=0;

	scanf("%d %d %d", &a, &b, &c);
	while (c > sum) {
		co++;
		day++;
		sum += a;
		if (co >= 7) {
			sum += b;
			co = 0;
		}
	}
	printf("%d\n", day);
	return 0;
}