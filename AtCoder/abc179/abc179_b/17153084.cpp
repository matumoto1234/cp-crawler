// detail: https://atcoder.jp/contests/abc179/submissions/17153084
#include <stdio.h>
int main() {
int N;
  int count=0;
 int a=0;
  int saikoro[100][2];
  
  scanf("%d",&N);
  
  for(int i=0;i<N;i++) {
	for(int j=0;j<2;j++) {
      scanf("%d",&saikoro[i][j]);
    }
  }
  
  for(int i=0;i<N-2;i++) {
      count=0;
    for(int j=0;j<3;j++) {
		if(saikoro[i+j][0]==saikoro[i+j][1]) {
          count++;
        if(count==3)
            a=count;
        }else{
          continue;
        }
    }
  }
    if(a>=3) {
      printf("Yes\n");
  }else{
      printf("No\n");
    }
    return 0;
  }            
