// detail: https://atcoder.jp/contests/abc177/submissions/16323900
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p=1e9+7;
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll n;
  cin>>n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  ll sum=0LL;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      sum+=(a[i]*a[j])%p;
      sum%=p;
    }
  }
  cout<<sum<<endl;
  return 0;
}