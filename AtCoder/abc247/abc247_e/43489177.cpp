// detail: https://atcoder.jp/contests/abc247/submissions/43489177
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(const vector<ll> &a) {
  ll sum = 0;
  ll cnt = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] == 1) {
      sum += cnt * (cnt + 1) / 2;
      cnt = 0;
    } else {
      cnt++;
    }
  }
  sum += cnt * (cnt + 1) / 2;
  return sum;
}

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  vector<int> a(n);
  for (auto &v: a) {
    cin >> v;
  }

  vector<ll> ex_x(n, 0), ex_y(n, 0), ex_xy(n, 0), all(n, 0);

  for (int i = 0; i < n; i++) {
    if (not(y <= a[i] and a[i] <= x)) {
      all[i] = 1;
      ex_x[i] = 1;
      ex_y[i] = 1;
      ex_xy[i] = 1;
    }

    if (a[i] == x) {
      ex_x[i] = 1;
      ex_xy[i] = 1;
    }

    if (a[i] == y) {
      ex_y[i] = 1;
      ex_xy[i] = 1;
    }
  }

  ll ans = solve(all);
  ans -= solve(ex_x);
  ans -= solve(ex_y);
  ans += solve(ex_xy);

  cout << ans << endl;
}
