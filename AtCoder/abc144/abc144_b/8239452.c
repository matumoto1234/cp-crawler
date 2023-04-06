// detail: https://atcoder.jp/contests/abc144/submissions/8239452
#include<stdio.h>
int main(void){
  int n;
  int flg=0;
  scanf("%d",&n);
  for(int i=1;i<10;i++){
    for(int j=1;j<10;j++){
      if(n==i*j){
        flg=1;
        break;
      }
    }
  }
  if(flg==1){
    printf("Yes\n");
  }
  else{
    printf("No\n");
  }
  return 0;
}