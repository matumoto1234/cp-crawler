// detail: https://atcoder.jp/contests/abc161/submissions/11559776
#include<stdio.h>
#include<math.h>
typedef long long int ll;
int main(){
  ll n,k,tmp;
  
  scanf("%lld %lld",&n,&k);
  tmp=n%k;
  ll tmp2=tmp-k;
  if(tmp2<0)tmp*=-1;
  if(tmp>tmp2){
    printf("%lld\n",tmp2);
  }
  else printf("%lld\n",tmp);
  return 0;
}