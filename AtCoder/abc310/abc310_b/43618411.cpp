// detail: https://atcoder.jp/contests/abc310/submissions/43618411
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, vector<int>>> pf(n);
  for (int i = 0; i < n; i++) {
    auto &[p, f] = pf[i];
    int c;

    cin >> p >> c;

    f = vector<int>(c);
    for (auto &v: f) {
      cin >> v;
    }

    sort(f.begin(), f.end());
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }

      auto [p1, f1] = pf[i];
      auto [p2, f2] = pf[j];

      if (p1 >= p2) {
        bool include = true;
        for (auto v1: f1) {
          int idx = lower_bound(f2.begin(), f2.end(), v1) - f2.begin();
          if (not(idx < (int)f2.size() and f2[idx] == v1)) {
            include = false;
            break;
          }
        }

        if (include) {
          if (p1 > p2 or f2.size() > f1.size()) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "No" << endl;
}
