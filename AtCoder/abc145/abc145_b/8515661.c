// detail: https://atcoder.jp/contests/abc145/submissions/8515661
#include<stdio.h>
#include<string.h>
int main(void)
{
  int n;
  int len,flg=0;
  char s[100000];
  
  scanf("%d %s",&n,s);
  len=strlen(s);
  for(int i=0;i<len/2;i++){
    if(a[i]!=a[len+i]){
      flg=1;
      break;
    }
  }
  if(flg==1){
    printf("No\n");
  }
  else{
    printf("Yes\n");
  }
  return 0;
}