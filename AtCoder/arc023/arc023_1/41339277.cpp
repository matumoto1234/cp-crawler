// detail: https://atcoder.jp/contests/arc023/submissions/41339277
#include <bits/stdc++.h>
using namespace std;

int elapsed_date(int y, int m, int d) {
  return 365 * y + y / 4 - y / 100 + y / 400 + (306 * (m + 1)) / 10 + d - 429;
}

int main() {
  int y, m, d;
  cin >> y >> m >> d;

  if (m == 1 or m == 2) {
    y--;
    m += 12;
  }

  cout << elapsed_date(2014, 5, 17) - elapsed_date(y, m, d) << endl;
}
