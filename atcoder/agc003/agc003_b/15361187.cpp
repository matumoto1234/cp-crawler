// detail: https://atcoder.jp/contests/agc003/submissions/15361187
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    if(a[i]!=0){
      if(i+1==n){
        ans += a[i] / 2;
      }
      else if(a[i+1]==0){
        ans += a[i] / 2;
      }else{
        ans += min(a[i], a[i + 1]);
        if(a[i]>a[i+1]){
          a[i] -= a[i + 1];
          a[i + 1] = 0LL;
          if(a[i]>1){
            ans += a[i] / 2;
          }
        }else{
          a[i + 1] -= a[i];
        }
      }
    }
    //cout << "ans="<<ans << endl;
  }
  cout << ans << endl;
  return 0;
}