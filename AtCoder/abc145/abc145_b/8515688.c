// detail: https://atcoder.jp/contests/abc145/submissions/8515688
#include<stdio.h>
#include<string.h>
int main(void)
{
  int n;
  int len,flg=0;
  char s[100000];
  
  scanf("%d %s",&n,s);
  len=strlen(s);
  if(n%2==0){
    printf("No\n");
    return 0;
  }
  for(int i=0;i<len/2;i++){
    if(s[i]!=s[len+i]){
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