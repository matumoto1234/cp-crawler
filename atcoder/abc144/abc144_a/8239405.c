// detail: https://atcoder.jp/contests/abc144/submissions/8239405
#include<stdio.h>
int main(void){
  int a,b;
  
  scanf("%d %d",&a,&b);
  if(a>=10||b>=10){
    printf("-1\n");
  }
  else{
    printf("%d\n",a*b);
  }
  return 0;
}