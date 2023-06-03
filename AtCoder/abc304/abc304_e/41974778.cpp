// detail: https://atcoder.jp/contests/abc304/submissions/41974778
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

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

  set<pair<int, int>> can_not_merge_leader_pairs;
  for (int i = 0; i < k; i++) {
    int lx = d.leader(x[i]);
    int ly = d.leader(y[i]);

    can_not_merge_leader_pairs.emplace(lx, ly);
    can_not_merge_leader_pairs.emplace(ly, lx);
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

    if(can_not_merge_leader_pairs.find(pair(lp, lq)) != can_not_merge_leader_pairs.end()) {
      cout << "No" << "\n";
      continue;
    }

    cout << "Yes" << "\n";
  }
}
