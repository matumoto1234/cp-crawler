// detail: https://atcoder.jp/contests/abc134/submissions/6504209
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
	for (i = n; i >= half; i--) {
		b[i] = a[i];
	}

	for (i = half - 1; i >= 0; i--) {
		co = 0;
		for (j = i; j < n; j += i+1) {
			if (b[i] == 1) {
				co++;
			}
		}
		if (co % 2 == 0) {
			if (a[i] == 0) {
				b[i] = 0;
			}
			else if(a[i]==1){
				b[i] = 1;
			}
		}
		else if(co % 2 == 1){
			if (a[i] == 0) {
				b[i] = 1;
			}
			else if(a[i] == 1){
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
	printf("\n");
	return 0;
}