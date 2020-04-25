// detail: https://atcoder.jp/contests/arc002/submissions/12306104
#include<stdio.h>
int main(void)
{
  int year;
  
  scanf("%d",&year);
  if(year%4==0&&year%100!=0||year%400==0){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}