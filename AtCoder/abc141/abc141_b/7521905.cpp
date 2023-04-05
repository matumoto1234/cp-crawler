// detail: https://atcoder.jp/contests/abc141/submissions/7521905
#include<stdio.h>
#include<string.h>
int main(void)
{
  char s[101];
  int len;
  int flg=0;
  
  scanf("%s",s);
  len=strlen(s);
  for(int i=0;i<len;i+=2){
    if(s[i]=='L'){
      flg=1;
      break;
    }
  }
  for(int i=1;i<len;i+=2){
    if(s[i]=='R'){
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
  