// detail: https://atcoder.jp/contests/abc146/submissions/8652794
#include<stdio.h>
int main(void)
{
  int n;
  char s[10001];
  
  scanf("%d %s",&n,s);
  for(int i=0;s[i]!='\0';i++){
    if(s[i]+n>'Z'){
      s[i]+=n;
      s[i]-='Z'-'A'+1;
    }
    else{
      s[i]+=n;
    }
  }
  printf("%s\n",s);
  return 0;
}