// detail: https://atcoder.jp/contests/diverta2019/submissions/14712703
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll r, g, b, n, ans = 0;
  cin >> r >> g >> b >> n;
  for (ll i = 0; i * r <= n; i++) {
    for (ll j = 0; i * r + j * g <= n; j++) {
      for (ll k = 0; i * r + j * g + k * b <= n; k++) {
        if (i * r + j * g + k * b == n) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}