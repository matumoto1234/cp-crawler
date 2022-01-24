// detail: https://atcoder.jp/contests/abc190/submissions/28775068
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n;
  cin>>n;
  
  ll ans = 0;
  for(ll i=1;i*i<=n;i++){
    ll sum = (1+i)*i/2;
    if((n-sum)%i==0) ans++;
  }
  
  cout<<2*ans<<endl;
}