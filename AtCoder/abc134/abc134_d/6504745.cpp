// detail: https://atcoder.jp/contests/abc134/submissions/6504745
#include<stdio.h>
int main(void) {
	int n;
	static int a[200000], b[200000]={0};
	int half, co,sum;
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
		sum = 0;//カウントリセット
		for (j = i; j < n; j += i+1) {
			if (b[j] == 1) {
				sum+=b[j];//ボールの数の合計
			}
		}
		if(sum%2!=0){
			b[i]=1;
		}
	}
	co = 0;
    for(i=0;i<n;i++){
        if(b[i]==1){
			co++;//1の数をカウント
		}
    }
	printf("%d\n",co);
	int cnt=0;
	for(i=0;i<n;i++){
		if(b[i]==1){
			printf("%d ",i+1);
		}
	}
	return 0;
}