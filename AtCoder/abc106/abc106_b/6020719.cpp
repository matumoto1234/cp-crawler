// detail: https://atcoder.jp/contests/abc106/submissions/6020719
#include<stdio.h>
int main(void)
{
  int n,co=0,cnt=0;
  int i ,j;
  
  scanf("%d",&n);
  for(i=1;i<n;i+=2){
    co=0;
    for(j=1;j<=i;j++){
      if(i%j==0){
      co++;
      }
    } 
    if(co==8){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  return 0;
}
