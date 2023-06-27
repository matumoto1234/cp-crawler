// detail: https://atcoder.jp/contests/typical90/submissions/42995347
#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }

  vector<int> sum_row(h, 0), sum_col(w, 0);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      sum_row[i] += a[i][j];
      sum_col[j] += a[i][j];
    }
  }

  vector<vector<int>> b(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      b[i][j] = sum_row[i] + sum_col[j] - a[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j) {
        cout << ' ';
      }
      cout << b[i][j];
    }
    cout << endl;
  }
}
