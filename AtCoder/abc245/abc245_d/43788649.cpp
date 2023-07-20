// detail: https://atcoder.jp/contests/abc245/submissions/43788649
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

  vector<int> b(m + 1, 0);
  for (int i = 0; i < m + 1; i++) {
    int sum = 0;
    for (int j = 1; j <= i; j++) {
      if (n - j < 0 or m - (i - j) < 0) {
        continue;
      }
      sum += a[n - j] * b[m - (i - j)];
    }

    b[m - i] = (c[n + m - i] - sum) / a[n];
  }

  for (int i = 0; i < m + 1; i++) {
    if (i) {
      cout << ' ';
    }
    cout << b[i];
  }
  cout << endl;
}
