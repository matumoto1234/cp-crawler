// detail: https://atcoder.jp/contests/agc025/submissions/29857326
#include <stdio.h>

int sum_digit(int n){
  int sum=0;
  while(n>0){
    sum+=n%10;
    n/=10;
  }
  return sum;
}

int main(){
  int n;
  scanf("%d",&n);
  
  int ans = 1<<30;
  
  for(int a=1;a<n;a++){
    int b = n-a;
    int val = sum_digit(a) + sum_digit(b);
    
    if(ans>val)ans=val;
  }
  
  printf("%d\n",ans);
}