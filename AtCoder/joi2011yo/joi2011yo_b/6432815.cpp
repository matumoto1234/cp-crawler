// detail: https://atcoder.jp/contests/joi2011yo/submissions/6432815
#include <stdio.h>
int main(void)
{
	int n;
	char s[11], a[101][11];
	int i, j, flag, co = 0, k;
	int temp;

	scanf("%s", s);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < 10; j++) {
			if (s[0] == a[i][j]) {
				flag = 0;
				temp = j;
				for (k = 0; s[k] != '\0'; k++) {
					if (k != 0)temp++;
					if (s[k] != a[i][temp]) {
						if (a[i][temp] == '\0') {
							temp = 0;
						}
						else {
							flag = 1;
							break;
						}
					}
				}
				if (flag == 0) {
					co++;
					break;
				}
			}
		}
	}
	printf("%d\n", co);
	return 0;
}