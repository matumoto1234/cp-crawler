// detail: https://atcoder.jp/contests/abc144/submissions/41339407
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> divisor(ll n) {
  vector<ll> divs;

  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divs.push_back(i);

      if (i * i != n) {
        divs.push_back(n / i);
      }
    }
  }

  return divs;
}

int main() {
  ll n;
  cin >> n;

  auto divs = divisor(n);

  ll ans = 1LL << 60;

  for (auto d: divs) {
    ll dx = d - 1;
    ll dy = n / d - 1;
    ans = min(ans, dx + dy);
  }

  cout << ans << endl;
}
