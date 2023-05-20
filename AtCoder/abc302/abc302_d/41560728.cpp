// detail: https://atcoder.jp/contests/abc302/submissions/41560728
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ll n, m, d;
  cin >> n >> m >> d;

  vector<ll> a(n);
  for (auto &v: a) {
    cin >> v;
  }

  vector<ll> b(m);
  for (auto &v: b) {
    cin >> v;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans = -1;

  for (int i = n - 1; i >= 0; i--) {
    // abs(a[i] - b[j]) <= dなるjの中で最大のjを選びたい
    // => b[j] <= a[i] + dなるjの中で最大のjを選びたい
    //    ただし、abs(a[i] - b[j]) <= dを満たさない場合はNG
    int valid = 0;
    int invalid = m;

    auto is_valid = [&](int mid) -> bool {
      return b[mid] <= a[i] + d;
    };

    while (abs(valid - invalid) > 1) {
      int mid = (valid + invalid) / 2;
      if (is_valid(mid)) {
        valid = mid;
      } else {
        invalid = mid;
      }
    }

    int j = valid;

    if (abs(a[i] - b[j]) <= d) {
      ans = max(ans, a[i] + b[j]);
    }
  }

  cout << ans << endl;
}
