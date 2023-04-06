// detail: https://atcoder.jp/contests/abc123/submissions/4846033
#include<stdio.h>
int main(void)
{
	int antena[5];
	int k;
	int i, j;
	int flag;

	for (i = 0; i < 5; i++) {
		scanf("%d", &antena[i]);
	}
	scanf("%d", &k);
	for (i = 0; i < 5; i++) {
		for (j = 1; j < 5; j++) {
			if (antena[i] < antena[j]) {
				if (k < antena[i] - antena[j]) {
					flag = 1;
				}
				else {
					if (k < antena[j] - antena[i]) {
						flag = 1;
					}
				}
			}
		}
	}
	if (flag == 1) {
		printf(":(\n");
	}
	else {
		printf("Yay!\n");
	}
	return 0;
}