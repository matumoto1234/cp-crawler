// detail: https://atcoder.jp/contests/panasonic2020/submissions/10895837
#include<math.h>
#include<stdio.h>
typedef long double ld;
int main(void)
{
  ld a,b,c;
  ld eps = 1.0^-14;
  scanf("%lf %lf %lf",&a,&b,&c);
  if(sqrt(a)+sqrt(b)+eps<sqrt(c)){
    printf("Yes");
  }
  else {
    printf("No");
  }
  return 0;
}
