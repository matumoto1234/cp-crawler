// detail: https://atcoder.jp/contests/agc035/submissions/6387648
#include<stdio.h>
int main(void) {
	int n, i, j, k;
	int a[100000];
	int flag = 0;
	int flag1 = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != 0) {
			flag1 = 1;//全ての数が0かどうか判断
		}
	}
	if (flag1 == 0) {//全部0だったら終了
		printf("Yes\n");
		return 0;
	}
	int co0 = 0, list[30], listi = 0, flagl = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == 0) {
			co0++;//0の数をカウント
		}
		else {
			for (j = 0; j < listi; j++) {
				if (list[j] == a[i]) {
					flagl = 1;//a[]の値はlistにあるか判断
					break;
				}
			}
			if (flagl == 0) {
				list[listi++] = a[i];//ないときは加える
			}
			else {
				flagl = 0;
			}
		}
	}
	if (co0 == n) {
		printf("Yes\n");//0の数がnと同じだったら終了
		return 0;
	}
	int co = 0, cox, coy, coz, co2 = 0;
	cox = coy = coz = 0;
	if (listi == 2) {//a[]の値が二つだったら入る
		for (i = 0; i < n; i++) {
			if (list[0] == a[i]) {
				co++;
			}
			else if(list[1]==a[i]){
				co2++;
			}
		}
		if (co == co0) {
			if (co2 == (2 * n) / 3 && co0 == n / 3) {
				printf("Yes\n");
				return 0;
			}
		}
		else if (co2 == co0) {
			if (co == (2 * n) / 3 && co0 == n / 3) {
				printf("Yes\n");
				return 0;
			}
		}
	}
	if (listi == 3) {
		for (i = 0; i < n; i++) {
			if (list[0] == a[i]) {
				cox++;
			}
			else if (list[1] == a[i]) {
				coy++;
			}
			else if (list[2] == a[i]) {
				coz++;
			}
		}
		if (cox == coy == coz == n / 3) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}