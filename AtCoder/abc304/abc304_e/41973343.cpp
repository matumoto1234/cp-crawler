// detail: https://atcoder.jp/contests/abc304/submissions/41973343
#include <bits/stdc++.h>
using namespace std;

struct UnionFindUndo {
  vector<int> data;
  stack<pair<int, int>> history;

  UnionFindUndo(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    history.emplace(x, data[x]);
    history.emplace(y, data[y]);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if (data[k] < 0)
      return (k);
    return (find(data[k]));
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int size(int k) {
    return (-data[find(k)]);
  }

  void undo() {
    data[history.top().first] = history.top().second;
    history.pop();
    data[history.top().first] = history.top().second;
    history.pop();
  }

  void snapshot() {
    while (history.size())
      history.pop();
  }

  void rollback() {
    while (history.size())
      undo();
  }
};


int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  UnionFindUndo d(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    u--, v--;

    d.unite(u, v);
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

    int lp = d.find(p);
    int lq = d.find(q);


    if (lp > lq) {
      swap(lp, lq);
    }

    auto itr = memo.find(pair(lp, lq));
    if (itr != memo.end()) {
      bool is_good = itr->second;
      cout << (is_good ? "Yes" : "No") << "\n";
      continue;
    }

    d.unite(lp, lq);

    bool &is_good_graph2 = memo[pair(lp, lq)];
    is_good_graph2 = true;
    for (int i = 0; i < k; i++) {
      if (d.same(x[i], y[i])) {
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

    d.undo();
  }
}
