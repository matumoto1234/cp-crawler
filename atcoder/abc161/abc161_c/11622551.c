// detail: https://atcoder.jp/contests/abc161/submissions/11622551
#include<stdio.h>
#include<math.h>
typedef long long int lli;
lli llabs(lli x){
  if(x<(lli)0){
    x*=(lli)-1;
  }
  return x;
}
int main(void)
{
  lli n,k;
  
  scanf("%lld %lld",&n,&k);
  if(n>=k){
    lli tmp=n%k;
    lli tmp2=llabs(tmp-k);
    if(tmp>tmp2)printf("%lld\n",tmp2);
    else printf("%lld\n",tmp);
  }
  else{
    lli tmp=llabs(n-k);
    if(n>tmp)printf("%lld\n",tmp);
    else printf("%lld\n",n);
  }
  
  return 0;
}
