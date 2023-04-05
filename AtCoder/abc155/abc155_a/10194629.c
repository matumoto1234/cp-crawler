// detail: https://atcoder.jp/contests/abc155/submissions/10194629
#include<stdio.h>
int main(void)
{
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  if(a==b&&a!=c){
    printf("Yes\n");
  }
  else if(b==c&&b!=a){
    printf("Yes\n");
  }
  else if(a==c&&a!=b){
    printf("Yes\n");
  }
  else{
    printf("No\n");
  }
  return 0;
}
