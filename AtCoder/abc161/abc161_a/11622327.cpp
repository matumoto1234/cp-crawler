// detail: https://atcoder.jp/contests/abc161/submissions/11622327
#include<stdio.h>
int main(void)
{
  int a,b,c;
  int tmp;
  
  scanf("%d %d %d",&a,&b,&c);
  tmp=a;
  a=b;
  b=tmp;
  tmp=a;
  a=c;
  c=tmp;
  printf("%d %d %d\n",a,b,c);
  return 0;
}