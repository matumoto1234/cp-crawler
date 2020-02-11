// detail: https://atcoder.jp/contests/abc154/submissions/10044315
#include<stdio.h>
int main(void)
{
  char s[101];
  scanf("%s",s);
  for(int i=0;s[i]!='\0';i++){
    s[i]='x';
  }
  printf("%s\n",s);
  return 0;
}