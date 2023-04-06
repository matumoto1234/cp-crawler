// detail: https://atcoder.jp/contests/arc107/submissions/17763412
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll n,ll k){
  return min(k-1,2*n+1-k);
}

int main(){
  ll n,k;
  cin>>n>>k;

  ll ans=0;
  for(ll i=2;i<=2*n;i++){
    ll sum=f(n,i)*f(n,i-k);
    ans+=sum;
  }
  cout<<ans<<endl;
  return 0;
}