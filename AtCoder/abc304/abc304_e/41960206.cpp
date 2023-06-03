// detail: https://atcoder.jp/contests/abc304/submissions/41960206
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  dsu d(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    u--, v--;

    d.merge(u, v);
  }

  int k;
  cin >> k;

  vector<int> x(k), y(k);
  for (int i = 0; i < k; i++) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;
  }

  bool is_good_graph = true;
  for (int i = 0; i < k; i++) {
    if (d.same(x[i], y[i])) {
      is_good_graph = false;
      break;
    }
  }

  map<pair<int, int>, bool> memo;

  int Q;
  cin >> Q;

  while (Q--) {
    int p, q;
    cin >> p >> q;

    p--, q--;

    if (not is_good_graph) {
      cout << "No"
           << "\n";
      continue;
    }

    int lp = d.leader(p);
    int lq = d.leader(q);

    auto itr = memo.find(pair(lp, lq));
    if (itr != memo.end()) {
      bool is_good = itr->second;
      cout << (is_good ? "Yes" : "No") << "\n";
      continue;
    }

    auto d2 = d;
    d2.merge(lp, lq);

    bool &is_good_graph2 = memo[pair(lp, lq)];
    is_good_graph2 = true;
    for (int i = 0; i < k; i++) {
      if (d2.same(x[i], y[i])) {
        is_good_graph2 = false;
      }
    }

    if (is_good_graph2) {
      cout << "Yes"
           << "\n";
    } else {
      cout << "No"
           << "\n";
    }
  }
}
