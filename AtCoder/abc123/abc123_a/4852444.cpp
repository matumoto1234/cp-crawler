// detail: https://atcoder.jp/contests/abc123/submissions/4852444
#include<stdio.h>
int main(void)
{
	int antena[5];
	int k;
	int i, j;
	int flag = 0;

	for (i = 0; i < 5; i++) {
		scanf("%d", &antena[i]);
	}
	scanf("%d", &k);
	for (i = 0; i < 5; i++) {
		for (j = i + 1; j < 5; j++) {
			if (antena[j] > antena[i]) {
				if (k < antena[j] - antena[i]) {
					flag = 1;
				}
			}
		}
	}
	if (flag == 1) {
		printf(":(\n");
	}
	else {
		printf("Yay!");
	}
	return 0;
}