// detail: https://atcoder.jp/contests/abc174/submissions/15624732
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, wcnt, wstart, rcnt;
  string s;
  cin >> n >> s;
  wcnt = rcnt = 0;
  wstart = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'W') {
      if (wstart == -1) {
        wstart = i;
      }
      wcnt++;
    } else {
      if (wstart >= 0) {
        rcnt++;
      }
    }
  }
  int wcnt2 = 0;
  for (int i = wstart; i < wstart + rcnt && wstart + rcnt < n; i++) {
    if (s[i] == 'W') {
      wcnt2++;
    }
  }
  // cout << "wstart=" << wstart << " rcnt=" << rcnt << " wcnt=" << wcnt << "
  // wcnt2=" << wcnt2 << endl;
  cout << min(wcnt, wcnt2) << endl;
  return 0;
}