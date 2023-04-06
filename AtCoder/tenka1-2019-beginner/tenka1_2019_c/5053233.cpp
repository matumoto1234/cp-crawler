// detail: https://atcoder.jp/contests/tenka1-2019-beginner/submissions/5053233
#include<stdio.h>
int main(void)
{
	int n;
	int i;
	char a[200001];
	int co, co1, co2, minco1,minco2;

	co = co1 = co2 = minco1 = minco2 = 0;
	scanf("%d", &n);
	scanf("%s", a);
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] == '#') {
			co1++;
		}
		else if (a[i] == '.') {
			co2++;
		}
	}
	if (co1 > co2) {
		for (i = 0; a[i] != '\0'; i++) {
			if (a[i] == '#') {
				if (a[i + 1] == '.') {
					a[i + 1] = '#';
					co++;
				}
			}
		}
	}
	else if(co1 < co2){
		for (i = 0; a[i] != '\0'; i++) {
			if (a[i] == '.') {
				if (a[i - 1] == '#') {
					a[i - 1] = '.';
					co++;
				}
			}
		}
	}
	else if (co1 == co2) {
		co = n / 2;
	}
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] == '#') {
			if (a[i + 1] == '.') {
				a[i + 1] = '#';
				minco1++;
			}
		}
	}
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] == '.') {
			if (a[i - 1] == '#') {
				a[i - 1] = '.';
				minco2++;
			}
		}
	}
	if (minco1 < minco2) {
		printf("%d\n", minco1);
	}
	else {
		printf("%d\n", minco2);
	}
	//printf("%d\n", co);
	return 0;
}