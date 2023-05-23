// detail: https://atcoder.jp/contests/abc091/submissions/41652996
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &v: a) {
    cin >> v;
  }

  vector<int> b(n);
  for (auto &v: b) {
    cin >> v;
  }

  using ll = long long;

  ll ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans ^= a[i] + b[j];
    }
  }

  cout << ans << endl;
}
