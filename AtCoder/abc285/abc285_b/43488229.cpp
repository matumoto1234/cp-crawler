// detail: https://atcoder.jp/contests/abc285/submissions/43488229
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  for (int i = 1; i <= n; i++) {
    int ans = 0;

    for (int l = 0; l < n; l++) {
      if (i + l >= n or s[l] == s[i + l]) {
        ans = l;
        break;
      }
    }

    cout << ans << endl;
  }
}
