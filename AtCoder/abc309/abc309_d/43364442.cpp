// detail: https://atcoder.jp/contests/abc309/submissions/43364442
#include <bits/stdc++.h>
using namespace std;

//BEGIN CUT HERE
template <typename T>
struct Dijkstra {
  struct Edge {
    int to;
    T cost;
    Edge(int to, T cost): to(to), cost(cost) {}
    bool operator<(const Edge &o) const {
      return cost > o.cost;
    }
  };

  vector<vector<Edge>> G;
  vector<T> ds;
  vector<int> bs;
  Dijkstra(int n): G(n) {}

  void add_edge(int u, int v, T c) {
    G[u].emplace_back(v, c);
  }

  void build(int s) {
    int n = G.size();
    ds.assign(n, numeric_limits<T>::max());
    bs.assign(n, -1);

    priority_queue<Edge> pq;
    ds[s] = 0;
    pq.emplace(s, ds[s]);

    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int v = p.to;
      if (ds[v] < p.cost)
        continue;
      for (auto e: G[v]) {
        if (ds[e.to] > ds[v] + e.cost) {
          ds[e.to] = ds[v] + e.cost;
          bs[e.to] = v;
          pq.emplace(e.to, ds[e.to]);
        }
      }
    }
  }

  T operator[](int k) {
    return ds[k];
  }

  vector<int> restore(int to) {
    vector<int> res;
    if (bs[to] < 0)
      return res;
    while (~to)
      res.emplace_back(to), to = bs[to];
    reverse(res.begin(), res.end());
    return res;
  }
};
//END CUT HERE

using ll = long long;

int main() {
  int n1, n2, m;
  cin >> n1 >> n2 >> m;

  Dijkstra<ll> d1(n1), d2(n2);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    a--, b--;

    if (0 <= a and a < n1) {
      d1.add_edge(a, b, 1);
      d1.add_edge(b, a, 1);
    } else {
      a -= n1;
      b -= n1;
      d2.add_edge(a, b, 1);
      d2.add_edge(b, a, 1);
    }
  }

  d1.build(0);
  d2.build(n2 - 1);

  ll max_d1 = 0;

  for (int to = 0; to < n1; to++) {
    max_d1 = max(max_d1, d1[to]);
  }

  ll max_d2 = 0;

  for (int to = 0; to < n2; to++) {
    max_d2 = max(max_d2, d2[to]);
  }

  cout << max_d1 + max_d2 + 1 << endl;
}
