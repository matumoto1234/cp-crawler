// detail: https://atcoder.jp/contests/abc172/submissions/15806395
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n,m,k;
  cin>>n>>m>>k;
  vector<ll> suma(n+1,0),sumb(m+1,0);
  vector<ll> a(n),b(m);
  for(ll i=0;i<n;i++){
    cin>>a[i];
    suma[i+1]+=a[i]+suma[i];
  }
  for(ll i=0;i<m;i++){
    cin>>b[i];
    sumb[i+1]+=b[i]+sumb[i];
  }
  ll lastj=m,ans=0;
  for(ll i=0;i<=n;i++){
    if(suma[i]>k){
      break;
    }
    for(ll j=lastj;j>=0;j--){
      if(suma[i]+sumb[j]<=k){
        ans=max(i+j,ans);
        break;
      }
      lastj=j;
    }
  }
  cout<<ans<<endl;
  return 0;
}