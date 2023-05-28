// detail: https://atcoder.jp/contests/arc161/submissions/41814584
#include <bits/stdc++.h>
using namespace std;

constexpr char newl = '\n';

#define int long long

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, d;
  cin >> n >> d;

  if (n * d > n * (n - 1) / 2) {
    cout << "No" << newl;
    return 0;
  }

  cout << "Yes" << newl;

  for (int i = 1; i <= d; i++) {
    vector<int> used(n, false);

    auto dfs = [&](auto &&f, int v) {
      if (used[v]) {
        return;
      }

      used[v] = true;
      int to = v + i;
      to %= n;

      cout << v + 1 << ' ' << to + 1 << newl;

      f(f, to);
    };

    for (int j = 0; j < n; j++) {
      dfs(dfs, j);
    }
  }
}
