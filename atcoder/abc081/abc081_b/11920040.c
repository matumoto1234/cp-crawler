// detail: https://atcoder.jp/contests/abc081/submissions/11920040
#include<stdio.h>
int main(void){
  int n,flg=0,cnt=0,a[200];
  int min=100000000;
  
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    cnt=0;
    if(a[i]%2!=0){
      flg=1;
    }
    while(a[i]%2==0){
      cnt++;
      a[i]/=2;
    }
    if(min>cnt&&cnt>=1){
      min=cnt;
    }
  }
  if(flg==0){
    printf("%d",min);
  }else {
    printf("0\n");
  }
  return 0;
}