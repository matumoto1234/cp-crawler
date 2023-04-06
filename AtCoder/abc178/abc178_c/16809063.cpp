// detail: https://atcoder.jp/contests/abc178/submissions/16809063
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p = 1e9+7;

ll llpowmod(ll a,ll e){
  if(e==0){
    return 1;
  }
  if(e%2==0){
    ll ret=llpowmod(a,e/2);
    return (ret*ret)%p;
  }else{
    ll ret=llpowmod(a,e-1)*a;
    return ret%p;
  }
}
int main(){
  ll n;
  cin>>n;
  cout<<llpowmod(10LL,n)-2*llpowmod(9LL,n)+llpowmod(8LL,n)<<endl;
  return 0;
}