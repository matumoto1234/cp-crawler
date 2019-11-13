// detail: https://atcoder.jp/contests/abc125/submissions/8419754
#include<stdio.h>
int main(void)
{
  int a,b;
  double t;
  double ans;
  int ans2;
  
  scanf("%d %d %lf",&a,&b,&t);
  t+=0.5;
  ans=t/(double)a;
  ans2=(int)ans;
  ans2*=b;
  printf("%d\n",ans2);
  return 0;
}