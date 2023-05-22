// detail: https://atcoder.jp/contests/abc302/submissions/41567376
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<set<int>> g(n);

  int isolation = n;

  for (int i = 0; i < q; i++) {
    int op;
    cin >> op;

    if (op == 1) {
      int u, v;
      cin >> u >> v;

      u--, v--;

      int iso = 0;
      if (g[u].empty()) {
        iso++;
      }
      if (g[v].empty()) {
        iso++;
      }

      g[u].insert(v);
      g[v].insert(u);

      int iso2 = 0;
      if (g[u].empty()) {
        iso2++;
      }
      if (g[v].empty()) {
        iso2++;
      }

      int diff = iso - iso2;
      isolation -= diff;
    } else if (op == 2) {
      int v;
      cin >> v;

      v--;

      int iso = 0;

      for (int to: g[v]) {
        g[to].erase(v);
        if (g[to].empty()) {
          iso++;
        }
      }

      if (g[v].empty()) {
        iso--;
      }
      g[v] = {};
      iso++;

      isolation += iso;
    }

    cout << isolation << "\n";
  }
}
