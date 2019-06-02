// detail: https://atcoder.jp/contests/agc034/submissions/5751826
#include<stdio.h>
int main(void)
{
  int n,a,b,c,d;
  char s[200001];
  int i;
  scanf("%d",&n);
  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);
  scanf("%d",&d);
  scanf("%s",s);
  for(i=0;i<n;i++){
    if(s[i]=='#'){
      if(s[i+1]=='#'){
        printf("No");
        return 0;
      }
    }
  }
  printf("Yes");
  return 0;
}