// detail: https://atcoder.jp/contests/abc099/submissions/6257513
#include<stdio.h>
int main(void)
{
  int a,b;
  int i,n,co=0;
  scanf("%d %d",&a,&b);
  n=b-a;
  for(i=1;i<=n;i++){
	co=co+i;
  }
  printf("%d\n",co-b);
  return 0;
}
