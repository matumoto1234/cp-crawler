// detail: https://atcoder.jp/contests/abc144/submissions/8239544
#include<stdio.h>
#include<math.h>
#include<limits.h>
typedef long long int lli;
int main(void){
  lli n;
  lli min=LLONG_MAX;
  scanf("%lld",&n);
  for(int i=1;i<(int)sqrt(n);i++){
    if(n%i==0){
      if(min>n/i+i-2){
        min=n/i+i-2;
      }
    }
  }
  printf("%lld\n",min);
  return 0;
}