// detail: https://atcoder.jp/contests/abc309/submissions/43377693
#include <bits/stdc++.h>
using namespace std;

//BEGIN CUT HERE
struct TopologicalSort {
  vector<vector<int>> G;
  vector<int> indeg;
  TopologicalSort(int n): G(n), indeg(n, 0) {}

  void add_edge(int s, int t) {
    G[s].emplace_back(t);
    indeg[t]++;
  }

  vector<int> build() {
    int n = G.size();

    queue<int> que;
    vector<int> used(n, 0);
    auto push = [&](int v) {
      if (used[v])
        return;
      que.emplace(v);
      used[v] = 1;
    };

    for (int i = 0; i < n; i++)
      if (indeg[i] == 0)
        push(i);

    vector<int> ps;
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      ps.emplace_back(v);
      for (int u: G[v]) {
        indeg[u]--;
        if (indeg[u] == 0)
          push(u);
      }
    }

    if (n != (int)ps.size())
      return {};
    return ps;
  }
};
//END CUT HERE

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> p(n - 1);
  for (auto &v: p) {
    cin >> v;
    v--;
  }

  vector<int> x(m), y(m);
  map<int, int> x_to_y;
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];

    x[i]--;

    x_to_y[x[i]] = max(x_to_y[x[i]], y[i]);
  }


  vector<vector<int>> adj_list(n);
  TopologicalSort topo(n);

  for (int i = 0; i < n - 1; i++) {
    topo.add_edge(p[i], i + 1);
    adj_list[p[i]].push_back(i + 1);
  }

  vector<int> vs = topo.build();

  vector<int> max_y(n, -1);
  auto dfs = [&](auto &&f, int v) -> void {
    // cout << "v:" << v << " x_to_y[v]:" << x_to_y[v] << endl;

    if (x_to_y[v] != 0) {
      max_y[v] = max(max_y[v], x_to_y[v]);
    }

    for (auto child: adj_list[v]) {
      max_y[child] = max(max_y[child], max_y[v] - 1);
      f(f, child);
    }
  };

  // for (int i = 0; i < n; i++) {
  //   cout << vs[i] << ' ';
  // }
  // cout << endl;

  dfs(dfs, vs[0]);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    // cout << "i:" << i << " max_y[i]:" << max_y[i] << endl;
    if (max_y[i] >= 0) {
      ans++;
    }
  }

  cout << ans << endl;
}
