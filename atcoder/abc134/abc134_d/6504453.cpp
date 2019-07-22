// detail: https://atcoder.jp/contests/abc134/submissions/6504453
#include<stdio.h>
int main(void) {
	int n;
	static int a[200000], b[200000] = { 0 };
	int half, co;
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	/*半分までの確定している部分をb[i]に入れる*/
	if (n % 2 == 0) {
		half = n / 2;
	}
	for (i = n; i > half; i--) {
		b[i] = a[i];
	}
	/*半分よりまえの部分をb[i]に入れる*/
	for (i = half; i >= 0; i--) {
		co = 0;//カウントリセット
		for (j = i; j < n; j += i+1) {
			if (b[j] == 1) {
				co++;//ボールが入っている箱の数をカウント
			}
		}
		if (co % 2 == 0) {//ボールが偶数個入っていたら
			if (a[i] == 0) {//個数の和が0なら
				b[i] = 0;
			}
			else if(a[i]==1){//偶数の和が1なら
				b[i] = 1;
			}
		}
		else if(co % 2 == 1){//ぼーるが奇数個入っていたら
			if (a[i] == 0) {//個数の和が0なら
				b[i] = 1;
			}
			else if(a[i] == 1){//個数の和が1なら
				b[i] = 0;
			}
		}
	}
	co = 0;
    for(i=0;i<n;i++){
        if(b[i]==1){
			co++;
		}
    }
	printf("%d\n",co);
	for(i=0;i<n;i++){
		if(b[i]==1){
			printf("%d ",i+1);
		}
	}
	return 0;
}