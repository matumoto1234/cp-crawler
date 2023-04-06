// detail: https://atcoder.jp/contests/agc037/submissions/6963793
#include<stdio.h>
#include<string.h>
int main(void){
  int len,i,co=0;
  char s[100001];
  scanf("%s",s);
  len=strlen(s);
  for(i=0;i<len;i++){
    if(s[i]!=s[i+1]){
      co++;
    }
    else{
      i++;
    }
  }
  printf("%d",len-co);
  return 0;
}
