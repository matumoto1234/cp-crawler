// detail: https://atcoder.jp/contests/abc178/submissions/16809133
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p = 1e9+7;

ll llpowmod(ll a,ll e){
  if(e==0){
    return 1LL;
  }
  if(e%2==0){
    ll ret=llpowmod(a,e/2);
    ret%=p;
    return (ret*ret)%p;
  }else{
    ll ret=llpowmod(a,e-1)*a;
    ret%=p;
    return ret%p;
  }
}
int main(){
  ll n;
  cin>>n;
  ll ans=(llpowmod(10LL,n)-2*llpowmod(9LL,n)+llpowmod(8LL,n));
  ans%=p;
  ans=(ans+p)%p;
  cout<<ans<<endl;
  return 0;
}