// detail: https://atcoder.jp/contests/abc245/submissions/43788413
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n + 1);
  for (auto &v: a) {
    cin >> v;
  }

  vector<int> c(n + m + 1);
  for (auto &v: c) {
    cin >> v;
  }

  if (n <= m) {
    for (int i = 0; i < m - n; i++) {
      a.push_back(0);
    }
  }

  vector<int> b(m + 1, 0);
  for (int i = 0; i < m + 1; i++) {
    int sum = 0;
    for (int j = i; j >= 1; j--) {
      sum += a[j] * b[i - j];
    }

    b[i] = (c[i] - sum) / a[0];
  }

  for (int i = 0; i < m + 1; i++) {
    if (i) {
      cout << ' ';
    }
    cout << b[i];
  }
  cout << endl;
}
