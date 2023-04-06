// detail: https://atcoder.jp/contests/abc173/submissions/15004431
#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, w, k, cnt, ans = 0;
  cin >> h >> w >> k;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  for (int gyou = 0; gyou < (1 << h); gyou++) {
    for (int retsu = 0; retsu < (1 << w); retsu++) {
      bitset<64> yoko(gyou);
      bitset<64> tate(retsu);
      cnt = 0;
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          if (tate[j] || yoko[i]) {
            continue;
          }
          if (s[i][j] == '#') {
            cnt++;
          }
        }
      }
      if (cnt == k) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}