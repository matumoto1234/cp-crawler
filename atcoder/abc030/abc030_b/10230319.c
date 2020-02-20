// detail: https://atcoder.jp/contests/abc030/submissions/10230319
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(void)
{
  int h,m;
  double ans;
  double itido=1.0/360.0;
  
  scanf("%d %d",&h,&m);
  if(h>=12){
    h-=12;
  }
  h*=5;
  if(abs(h-m)>60-(abs(h-m))){
    ans=itido*(double)(60-(abs(h-m)));
  }
  else{
    ans=itido*(double)(abs(h-m));
  }
  printf("%lf\n",ans);
  return 0;
}