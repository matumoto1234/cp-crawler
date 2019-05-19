// detail: https://atcoder.jp/contests/abc126/submissions/5481871
#include<stdio.h>
int main(void)
{
	int s;
	int mmyy, yymm;
	int senhyaku, juiti;
	
	scanf("%d", &s);
	mmyy = yymm = 1;
	senhyaku = s / 100;
	juiti = s % 100;
	if (senhyaku == 0 || senhyaku >= 13) {
		mmyy = 0;
	}
	if (juiti == 0 || juiti >= 13) {
		yymm = 0;
	}

	if (yymm == 0 && mmyy == 0) {
		printf("NA\n");
	}
	else if (yymm == 1 && mmyy == 0) {
		printf("YYMM\n");
	}
	else if (yymm == 0 && mmyy == 0) {
		printf("MMYY\n");
	}
	else if (yymm == 1 && mmyy == 1) {
		printf("AMBIGUOUS\n");
	}
	return 0;
}