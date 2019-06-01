// detail: https://atcoder.jp/contests/m-solutions2019/submissions/5731697
#include<stdio.h>
int main(void)
{
  char s[16];
  int i,co=0;
  scanf("%s",s);
  for(i=0;s[i]!='¥0';i++){
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
