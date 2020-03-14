// detail: https://atcoder.jp/contests/panasonic2020/submissions/10895673
#include<math.h>
#include<stdio.h>
typedef long double ld;
int main(void)
{
  ld a,b,c;
  scanf("%llf %llf %llf",&a,&b,&c);
  if(sqrt(a)+sqrt(b)<sqrt(c)){
    printf("Yes");
  }
  else {
    printf("No");
  }
  return 0;
}