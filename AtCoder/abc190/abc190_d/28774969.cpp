// detail: https://atcoder.jp/contests/abc190/submissions/28774969
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n;
  cin>>n;
  
  ll ans = 0;
  for(ll i=1;i*i<=n;i++){
    if((1+i)*i/2 == n) ans++;
  }
  
  cout<<2*ans<<endl;
}