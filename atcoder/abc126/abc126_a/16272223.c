// detail: https://atcoder.jp/contests/abc126/submissions/16272223
#include<stdio.h>
int main(){
  int n,k;
  char s[51];
  scanf("%d%d%s",&n,&k,s);
  k--;
  s[k]+='a'-'A';
  printf("%s\n",s);
  return 0;
}