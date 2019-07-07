// detail: https://atcoder.jp/contests/abc133/submissions/6298131
#include<stdio.h>
int main(void)
{
	long long int l, r;
	int i;
	long long int temp;

	scanf("%lld %lld", &l, &r);
	temp = l;
	if (r - l > 2019) {
		if (r % 2019 == 0) {
			printf("%lld\n", l*r % 2019);
		}
		else if (r % 2019 == 1) {
			printf("%lld\n", (r - 1)*r % 2019);
		}
		else {
			for (i = 2019; i < r; i += 2019) {
				if (i >= l) {
					printf("%lld\n", i*(i + 1) % 2019);
					break;
				}
			}
		}
	}
	else {
		printf("%lld\n", l*(l + 1) % 2019);
	}
	return 0;
}