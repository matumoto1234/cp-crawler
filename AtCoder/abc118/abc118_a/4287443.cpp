// detail: https://atcoder.jp/contests/abc118/submissions/4287443
#include<stdio.h>
int main(void)
{
  int a,b;
  scanf("%d");
  scanf("%d");
  if(b%a==0){
    printf("%d",a+b);
  }
  else{
    printf("%d",b-a);
  }
  return 0;
}