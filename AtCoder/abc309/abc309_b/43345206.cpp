// detail: https://atcoder.jp/contests/abc309/submissions/43345206
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<string> b = a;

  for (int j = 0; j < n - 1; j++) {
    b[0][j + 1] = a[0][j];
  }

  for (int i = 0; i < n - 1; i++) {
    b[i + 1][n - 1] = a[i][n - 1];
  }

  for (int j = n - 1; j >= 1; j--) {
    b[n - 1][j - 1] = a[n - 1][j];
  }

  for (int i = n - 1; i >= 1; i--) {
    b[i - 1][0] = a[i][0];
  }

  for (int i = 0; i < n; i++) {
    cout << b[i] << endl;
  }
}
