// detail: https://atcoder.jp/contests/abc122/submissions/4693184
#include<stdio.h>
int main(void)
{
	char a[11];
	int i,co,max;
	co =max= 0;

	scanf("%s", a);
	for (i = 0; a[i] != '\0'; i++) {
		switch (a[i]) {
		case 'A':
			co++;
			break;
		case 'C':
			co++;
			break;
		case 'T':
			co++;
			break;
		case 'G':
			co++;
			break;
		default:
			co = 0;
		}
		if (max < co) {
			max = co;
		}
	}
	printf("%d\n", max);
	return 0;
}