// detail: https://atcoder.jp/contests/abc141/submissions/7518325
#include<stdio.h>
#include<string.h>
int main(void)
{
  char sun[]="Sunny";
  char rei[]="Rainy";
  char cro[]="Cloudy";
  char s[100000];
  scanf("%s",s);
  if(strcmp(s,sun)==0){
	printf("%s\n",cro);
  }
  else if(strcmp(s,rei)==0){
    printf("%s\n",sun);
  }
  else{
    printf("%s\n",rei);
  }
  return 0;
}