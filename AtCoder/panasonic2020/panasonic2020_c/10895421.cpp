// detail: https://atcoder.jp/contests/panasonic2020/submissions/10895421
#include<math.h>
#include<stdio.h>
typedef double d;
int main(void)
{
  d a,b,c;
  scanf("%lf %lf %lf",&a,&b,&c);
  if(sqrt(a)+sqrt(b)>sqrt(c)){
    printf("Yes");
  }
  else {
    printf("No");
  }
  return 0;
}