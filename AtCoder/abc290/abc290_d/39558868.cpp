// detail: https://atcoder.jp/contests/abc290/submissions/39558868
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll n, d, k;
  cin >> n >> d >> k;

  k--;

  ll l = n / gcd(n, d);
  ll r = k % l;
  ll q = k / l;

  cout << (q + r * d) % n << "\n";
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
