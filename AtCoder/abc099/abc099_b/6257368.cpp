// detail: https://atcoder.jp/contests/abc099/submissions/6257368
#include<stdio.h>
int main(void)
{
  int n;
  int i,co=0;
  scanf("%d",&n);
  for(i=1;i<=999;i++){
	co=co+co+1;
    if(co>=n){
      break;
    }
  }
  printf("%d\n",co-n);
  return 0;
}