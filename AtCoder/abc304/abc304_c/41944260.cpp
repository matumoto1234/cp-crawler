// detail: https://atcoder.jp/contests/abc304/submissions/41944260
#include <bits/stdc++.h>
using namespace std;

int square_dist(int x, int y) {
  return x * x + y * y;
}

int main() {
  int n, d;
  cin >> n >> d;

  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  int square_d = d * d;

  vector<vector<int>> g(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }

      if (square_dist(x[i] - x[j], y[i] - y[j]) <= square_d) {
        g[i].push_back(j);
      }
    }
  }

  vector<int> visited(n, false);

  auto dfs = [&](auto &&f, int v) {
    if (visited[v]) {
      return;
    }

    visited[v] = true;
    for (auto to: g[v]) {
      f(f, to);
    }
  };

  dfs(dfs, 0);

  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      cout << "Yes"
           << "\n";
    } else {
      cout << "No"
           << "\n";
    }
  }
}
