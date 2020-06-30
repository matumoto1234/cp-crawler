// detail: https://atcoder.jp/contests/abc097/submissions/14873061
#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, ans = 1;
  bool flg = false;
  cin >> x;
  for (int i = 1; i <= x; i++) {
    long double tmpi = i;
    for (int j = 2; j < i; j++) {
      flg = false;
      if (i % j == 0) {
        long double tmpj = (long double)j;
        while (1) {
          if (tmpi == tmpj) {
            flg = true;
            break;
          }
          tmpi /= tmpj;
          if (tmpi < tmpj) {
            flg = false;
            break;
          }
        }
      }
      if (flg) {
        if (ans < i) {
          ans = i;
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}