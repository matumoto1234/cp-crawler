// detail: https://atcoder.jp/contests/abc119/submissions/4376731
#include<stdio.h>
int main(void)
{
	char a[30];
	scanf("%s", a);
	a[4] = '\0';//   スラッシュのところを\0にする
	a[7] = '\0';//   上に同じ
	
	int y, m, d;
	int i,year[15],month[15],day[15];
	for (i = 0; a[i] != '\0'; i++) {
		a[i] = a[i] - 0x30;//   a[]が文字列なので整数にする
		year[i] = a[i];//   year[]に整数の西暦を入れる
	}
	for (i = 5; a[i] != '\0'; i++) {
		a[i] = a[i] - 0x30;//   整数にする
		month[i - 5] = a[i];//   月を入れる
	}
	for (i = 8; a[i] != '\0'; i++) {
		a[i] = a[i] - 0x30;//   整数にする
		day[i - 8] = a[i];//  日を入れる
	}
	y = year[0] * 1000 + year[1] * 100 + year[2] * 10 + year[3];//   yを2019みたいな感じにしたい
	m = month[0] * 10 + month[1];//   mを04みたいな感じにしたい
	d = day[0] * 10 + day[1];//   dを30みたいな感じにしたい

	if (y <= 2019 && m <= 4 && d <= 30) {
		printf("Heisei\n");
	}
	else {
		printf("TBD\n");
	}
	return 0;
}