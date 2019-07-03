// detail: https://atcoder.jp/contests/joi2019yo/submissions/6223294
#include<stdio.h>
int main(void)
{
	int a,b,c;
	int i;
	int dayco = 0, sum = 0, co = 0;

	scanf("%d %d %d", &a, &b, &c);
	while(sum < c){
		co++;
		dayco++;
		if (dayco >= 7) {
			dayco = 0;
			sum += b;
		}
		sum += a;
	}
	printf("%d\n", co);
	return 0;
}