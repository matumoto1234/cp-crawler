// detail: https://atcoder.jp/contests/abc099/submissions/6257462
#include<stdio.h>
int main(void)
{
  int n;
  int i,co=0;
  scanf("%d",&n);
  for(i=0;i<999;i++){
	co=i*2+1
    if(co>=n){
      break;
    }
  }
  printf("%d\n",co-n);
  return 0;
}
