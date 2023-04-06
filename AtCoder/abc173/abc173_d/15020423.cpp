// detail: https://atcoder.jp/contests/abc173/submissions/15020423
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n, cnt = 0, ans = 0;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n, 0LL);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<ll>());
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      ans += a[i];
      cnt++;
      if (cnt >= n - 1) {
        break;
      }
    } else {
      ans += a[i];
      cnt++;
      if (cnt >= n - 1) {
        break;
      }
      ans += a[i];
      cnt++;
      if (cnt >= n - 1) {
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}