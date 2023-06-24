// detail: https://atcoder.jp/contests/abc307/submissions/42892521
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(7 * n);
  for (auto &v: a) {
    cin >> v;
  }

  vector<int> b(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 7; j++) {
      b[i] += a[7 * i + j];
    }
  }

  for (int i = 0; i < (int)b.size(); i++) {
    if (i) {
      cout << " ";
    }
    cout << b[i];
  }
  cout << endl;
}
