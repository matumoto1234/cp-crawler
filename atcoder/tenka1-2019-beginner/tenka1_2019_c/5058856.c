// detail: https://atcoder.jp/contests/tenka1-2019-beginner/submissions/5058856
#include<stdio.h>
int main(void)
{
	int n;
	int i, j;
	char a[200001];
	int co, co1, co2;

	co = co1 = co2 = 0;
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
		for (i = 0; a[i] != '\0'; i++) {
			if (a[i] == '#') {
				for (j = i + 1; a[j] != '\0'; j++) {
					if (a[j] == '.') {
						a[j-1] = '#';
						co++;
					}
				}
			}
		}
	}
	co1 = co2 = 0;
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] == '#') {
			co1++;
		}
		else if (a[i] == '.') {
			co2++;
		}
	}
	if (co1 == 0 || co2 == 0) {
		printf("%d\n", co);
	}
	else if (co1 > co2) {
		for (i = 0; a[i] != '\0'; i++) {
			if (a[i] == '#') {
				if (a[i + 1] == '.') {
					a[i + 1] = '#';
					co++;
				}
			}
		}
	}
	else if (co1 < co2) {
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
		for (i = 0; a[i] != '\0'; i++) {
			if (a[i] == '#') {
				for (j = i + 1; a[j] != '\0'; j++) {
					if (a[j] == '.') {
						a[j - 1] = '#';
						co++;
					}
				}
			}
		}
	}
	return 0;
}