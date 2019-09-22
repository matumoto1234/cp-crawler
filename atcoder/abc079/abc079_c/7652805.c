// detail: https://atcoder.jp/contests/abc079/submissions/7652805
#include<stdio.h>
int main(void)
{
  int a,b,c,d;
  scanf("%d",&a);
  d=a%10;
  c=a/10%10;
  b=a/100%10;
  a=a/1000;
  if(a+b+c+d==7){
    printf("%d+%d+%d+%d=7\n",a,b,c,d);
  }
  else if(a-b+c+d==7){
    printf("%d-%d+%d+%d=7\n",a,b,c,d);
  }
  else if(a+b-c+d==7){
    printf("%d+%d-%d+%d=7\n",a,b,c,d);
  }
  else if(a+b+c-d==7){
    printf("%d+%d+%d-%d=7\n",a,b,c,d);
  }
  else if(a-b-c+d==7){
    printf("%d-%d-%d+%d=7\n",a,b,c,d);
  }
  else if(a-b+c-d==7){
    printf("%d-%d+%d-%d=7\n",a,b,c,d);
  }
  else if(a+b-c-d==7){
    printf("%d+%d-%d-%d=7\n",a,b,c,d);
  }
  else if(a-b-c-d==7){
    printf("%d-%d-%d-%d=7\n",a,b,c,d);
  }
  return 0;
}
