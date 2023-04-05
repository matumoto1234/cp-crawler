// detail: https://atcoder.jp/contests/abc093/submissions/6747063
#include<stdio.h>
int main(void) {
	int a, b, k;
	int ans[10000];
	int count = 0;
	//int countb = 0;
	scanf("%d %d %d", &a, &b, &k);
	int x=0 ;
	int flag = 0;
	int count1 = 0;
	if (b <= k) {
		for (int i = a; i <= b; i++) {
			printf("%d\n", i);
		}
		return 0;
	}
	else {
		if (a == b) {
			printf("%d\n", a);
			return 0;
		}
		else {
			for (int i = a; i <=b; i++) {
              count1++;
              if(count1>k){
				break;
              }
				ans[count++] = i;
			}
          count1=0;
			for (int i = b; i >=a; i--) {
				flag = 0;
              count1++;
              if(count1>k){
                break;
              }
				for (int j = 0; j < count; j++) {
					if (ans[j] == i) {
						flag = 1;
						break;
					}
					
				}
				if (flag == 0) {
					ans[count++] = i;
				}
			}
			//int same = 0;
			//printf("%d %d\n", counta, countb);
			/*if(flag==1){
				same = counta - countb;
				if (same < 0) {
					same = -1 * same;
				}
				same++;
			}*/
			//printf("%d\n", same);
			/*for (int i = a; i <= a + k - 1 - same; i++) {
				//printf("2\n");
				printf("%d\n", i);
			}*/
			int temp;
			for (int i = 0; i < count - 1; i++) {
				for (int j = i + 1; j < count; j++) {
					if (ans[i] > ans[j]) {
						temp = ans[i];
						ans[i] = ans[j];
						ans[j] = temp;
					}
				}
			}

			for (int i = 0; i < count; i++) {
				printf("%d\n", ans[i]);
			}
		}
	}
	return 0;
}
