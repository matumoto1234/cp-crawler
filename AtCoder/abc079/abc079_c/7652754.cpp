// detail: https://atcoder.jp/contests/abc079/submissions/7652754
#include<stdio.h>
int main(void)
{
  int a,b,c,d;
  scanf("%d %d %d %d",&a,&b,&c,&d);
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