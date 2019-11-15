// detail: https://atcoder.jp/contests/abc090/submissions/8443890
#include<stdio.h>
#include<string.h>
int main(void)
{
  int a,b;
  int cnt=0;
  char suji[6];
  char tmp[4];
  int len,center,flg;
  
  scanf("%d %d",&a,&b);
  for(int i=a;i<=b;i++){
    flg=0;
    sprintf(suji,"%d",i);
    len=strlen(suji);
    if(len%2==0){
      center=len/2;
    }else{
      center=len/2+1;
    }
    for(int j=0;j<center;j++){
      if(suji[j]!=suji[len-j-1]){
        flg=1;
        break;
      }
    }
    if(flg==0){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  return 0;
}