// detail: https://atcoder.jp/contests/abc302/submissions/41582568
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> s(n);
  vector<vector<int>> g(n + m);

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    s[i] = vector<int>(a);
    for (auto &v: s[i]) {
      cin >> v;

      g[i].push_back(n + v - 1);
      g[n + v - 1].push_back(i);
    }
  }

  // bfs
  vector<int> used(n + m, false);
  vector<int> dist(n + m, 1 << 30);
  queue<int> q;
  for (int i = 0; i < n; i++) {
    for (auto v: s[i]) {
      if (v == 1) {
        q.push(i);
        used[i] = true;
        dist[i] = 0;
        break;
      }
    }
  }

  while (not q.empty()) {
    int v = q.front();
    q.pop();

    for (int to: g[v]) {
      if (used[to]) {
        continue;
      }

      dist[to] = dist[v] + 1;
      used[to] = true;
      q.push(to);
    }
  }

  int ans = 1 << 30;

  for (int i = 0; i < n; i++) {
    for (auto v: s[i]) {
      if (v == m) {
        ans = min(ans, dist[i] / 2);
        break;
      }
    }
  }

  if (ans >= 1 << 28) {
    ans = -1;
  }

  cout << ans << endl;
}
