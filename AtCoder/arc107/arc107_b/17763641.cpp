// detail: https://atcoder.jp/contests/arc107/submissions/17763641
#include<iostream>
using namespace std;
using ll = long long;

ll f(ll n,ll k){
  return min(k-1,2*n+1-k);
}

int main(){
  ll n,k;
  cin>>n>>k;

  ll ans=0;
  for(ll x=k;x<=2*n;x++){
    ll sum=f(n,x)*f(n,x-k);
    ans+=sum;
  }
  cout<<ans<<endl;
  return 0;
}