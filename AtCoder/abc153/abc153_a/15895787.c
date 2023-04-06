// detail: https://atcoder.jp/contests/abc153/submissions/15895787
#include <stdio.h>
int main()
{
  int H,A,s,a;
  
  scanf("%d%d",&H,&A);
  
  a=H/A:
  s=H%A;
  if(s==0){
    printf("%d",a);
  }
  else{
    a+=1;
    printf("%d",a);
  }
  return 0;
}