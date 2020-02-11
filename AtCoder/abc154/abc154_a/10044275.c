// detail: https://atcoder.jp/contests/abc154/submissions/10044275
#include<stdio.h>
#include<string.h>
int main(void)
{
  char s[11],t[11],u[11];
  int a,b;
  scanf("%s %s",s,t);
  scanf("%d %d %s",&a,&b,u);
  if(!strcmp(s,u)){
    printf("%d %d\n",a-1,b);
  }else if(!strcmp(t,u)){
    printf("%d %d\n",a,b-1);
  }
  return 0;
}