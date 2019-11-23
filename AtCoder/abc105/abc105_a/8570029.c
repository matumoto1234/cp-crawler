// detail: https://atcoder.jp/contests/abc105/submissions/8570029
#include<stdio.h>
int main(void)
{
  int n,k;
  
  scanf("%d %d",&n,&k);
  int a=n/k;
  int b=n%k;
  if(b>=1){
    printf("%d\n",1);
  }
  else{
    printf("%d\n",0);
  }
  return 0;
}