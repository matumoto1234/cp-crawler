// detail: https://atcoder.jp/contests/m-solutions2019/submissions/5732038
#include<stdio.h>
#include<string.h>
int main(void)
{
  char s[16];
  int i,co=0,len;
  scanf("%s",s);
  len=strlen(s);
  for(i=0;i<len;i++){
    if(s[i]=='x'){
      co++;
    }
  }
  if(co>=8){
    printf("NO");
  }
  else{
    printf("YES");
  }
  return 0;
}
