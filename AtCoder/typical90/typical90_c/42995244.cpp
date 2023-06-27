// detail: https://atcoder.jp/contests/typical90/submissions/42995244
#include <bits/stdc++.h>
using namespace std;

pair<int, int> dfs(const vector<vector<int>> &g, int idx, int par) {
  pair<int, int> ret(0, idx);
  for (auto &to: g[idx]) {
    if (to == par) {
      continue;
    }

    auto cost = dfs(g, to, idx);
    cost.first++;
    ret = max(ret, cost);
  }
  return ret;
}

int tree_diameter(const vector<vector<int>> &g) {
  auto p = dfs(g, 0, -1);
  auto q = dfs(g, p.second, -1);
  return (q.first);
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;

    a--, b--;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  cout << tree_diameter(g) + 1 << endl;
}
