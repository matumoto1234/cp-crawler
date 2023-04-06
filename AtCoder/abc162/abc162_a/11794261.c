// detail: https://atcoder.jp/contests/abc162/submissions/11794261
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  int n;
  
  scanf("%d",&n);
  int flg=0;
  if(n%10==7){
    flg=1;
  }
  n/=10;
  if(n%10==7){
    flg=1;
  }
  n/=10;
  if(n%10==7){
    flg=1;
  }
  if(flg==1)printf("Yes\n");
  else printf("No\n");
  
  return 0;
}