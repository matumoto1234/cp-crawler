// detail: https://atcoder.jp/contests/joi2008yo/submissions/6536832
#include<stdio.h>
void card(int *, int *);
int n;
int main(void)
{
	int a[1000], b[1000], i, j;
	int temp, flag, bi, fierd, nokori;
	int taro, hanako, do1, do2, co, rari;

	taro = hanako = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	/*ソート*/
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	/*花子のカード*/
	bi = 0;
	for (i = 1; i <= 2 * n; i++) {
		flag = 0;
		for (j = 0; j < n; j++) {
			if (i == a[j]) {
				flag = 1;
			}
		}
		if (flag == 0) {
			b[bi++] = i;
		}
	}
	/*メイン*/
	flag = 1;
	for (i = 0; i < n; i++) {
		do1 = do2 = rari = fierd = 0;
		if (flag == 1) {//太郎の番
			card(a, &fierd);
			do1 = 1;
			do2 = 0;
		}
		else if (flag == 2) {//花子の番
			card(b, &fierd);
			do1 = 0;
			do2 = 1;
		}
		do {
			nokori = 0;
			for (int h = 0; h < n; h++) {
				if (a[h] != 0) {
					nokori = 1;
					break;
				}
			}
			if (nokori == 0) {
				taro = 1;
				goto end;
			}
			nokori = 0;
			for (int h = 0; h < n; h++) {
				if (b[h] != 0) {
					nokori = 1;
					break;
				}
			}
			if (nokori == 0) {
				hanako = 1;
				goto end;
			}
			temp = fierd;
			if (do1 == 0) {
				card(a, &fierd);
				do1 = 1;
				do2 = 0;
			}
			else {
				card(b, &fierd);
				do1 = 0;
				do2 = 1;
			}
		} while (temp != fierd);
		if (do1 == 0) {
			flag = 1;
		}
		else {
			flag = 2;
		}
	}
	end:
	co = 0;
	if (taro == 1) {
		for (i = 0; i < n; i++) {
			if (b[i] != 0) {
				co++;
			}
		}
		printf("%d\n", co);
		co = 0;
		for (i = 0; i < n; i++) {
			if (a[i] != 0) {
				co++;
			}
		}
		printf("%d\n", co);
	}
	else if (hanako == 1) {
		for (i = 0; i < n; i++) {
			if (a[i] != 0) {
				co++;
			}
		}
		printf("%d\n", co);
		co = 0;
		for (i = 0; i < n; i++) {
			if (b[i] != 0) {
				co++;
			}
		}
		printf("%d\n", co);
	}
	return 0;
}
void card(int *dat, int *f)
{
	int i;
	for (i = 0; i < n; i++) {
		if (*f < dat[i]) {
			*f = dat[i];
			dat[i] = 0;
			break;
		}
	}
}