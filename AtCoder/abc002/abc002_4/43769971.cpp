// detail: https://atcoder.jp/contests/abc002/submissions/43769971
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  set<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;

    x--, y--;

    edges.emplace(x, y);
    edges.emplace(y, x);
  }

  for (int i = 0; i < n; i++) {
    edges.emplace(i, i);
  }

  int ans = 0;

  for (int bit = 1; bit < (1 << n); bit++) {
    vector<int> use(n, false);
    int use_cnt = 0;
    for (int i = 0; i < n; i++) {
      if (bit >> i & 1) {
        use[i] = true;
        use_cnt++;
      }
    }

    bool valid = true;
    for (int u = 0; u < n; u++) {
      for (int v = 0; v < n; v++) {
        if (use[u] and use[v]) {
          if (edges.find(pair(u, v)) == edges.end()) {
            valid = false;
            goto EXIT;
          }
        }
      }
    }

  EXIT:
    if (valid) {
      ans = max(ans, use_cnt);
    }
  }

  cout << ans << endl;
}
