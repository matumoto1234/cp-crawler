// detail: https://atcoder.jp/contests/agc003/submissions/15361639
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
    if (a[i] != 0) {
      if (i > 0) {
        if (a[i - 1] == 0) {
          if(i<n-1&&a[i+1]==0){
            ans += a[i] / 2;
            a[i] %= 2;
          }
        }else{
          if(a[i]>a[i-1]){
            ans += a[i - 1];
            a[i] -= a[i - 1];
            a[i - 1] = 0LL;
          }else{
            ans += a[i];
            a[i - 1] -= a[i];
            a[i] = 0LL;
          }
        }
      }
      if (i < n - 1) {
        if (a[i] > a[i + 1]) {
          ans += a[i + 1];
          a[i] -= a[i + 1];
          a[i + 1] = 0LL;
          if (a[i] >= 2) {
            ans += a[i] / 2;
          }
        } else {
          ans += a[i];
          a[i + 1] -= a[i];
          a[i] = 0LL;
        }
      } else {
        ans += min(a[i - 1], a[i]);
        a[i] -= a[i - 1];
        if (a[i] >= 2) {
          ans += a[i] / 2;
        }
      }
    }
    //cout << "ans=" << ans << endl;
  }
  cout << ans << endl;
  return 0;
}