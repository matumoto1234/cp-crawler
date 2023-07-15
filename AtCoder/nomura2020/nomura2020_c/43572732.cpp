// detail: https://atcoder.jp/contests/nomura2020/submissions/43572732
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long

bool is_invalid(vector<ll> a) {
  vector<ll> b(a.size(), 0);

  b.back() = a.back();
  for (int i = a.size() - 2; i >= 0; i--) {
    b[i] = (b[i + 1] + 1) / 2 + a[i];
    if (i <= 30 and b[i] > (1 << i)) {
      return true;
    }
  }

  if (b[0] > 1) {
    return true;
  }

  return false;
}

signed main() {
  int n;
  cin >> n;

  vector<ll> a(n + 1);
  for (auto &v: a) {
    cin >> v;
  }

  if (is_invalid(a)) {
    cout << -1 << endl;
    return 0;
  }

  vector<ll> c(a.size(), 0);
  c[0] = 1;
  for (int i = 1; i < min<int>(c.size(), 60); i++) {
    c[i] = 2 * (c[i - 1]) - a[i];
  }

  vector<ll> b(a.size(), 0);
  b.back() = a.back();
  for (int i = a.size() - 2; i >= 0; i--) {
    b[i] = b[i + 1] + a[i];
    if (1 <= i and i < 30) {
      b[i] = min(b[i], 2 * c[i - 1]);
    }
  }
  b.front() = min(b.front(), 1LL);

  cout << accumulate(b.begin(), b.end(), 0LL) << endl;
}
