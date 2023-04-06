// detail: https://atcoder.jp/contests/nikkei2019-qual/submissions/14883737
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  vector<int> cnt(3, 0);
  vector<string> s(3);
  cin >> n >> s[0] >> s[1] >> s[2];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == j) {
        continue;
      }
      for (int k = 0; k < n; k++) {
        if (s[i][k] != s[j][k]) {
          cnt[i]++;
        }
      }
    }
  }
  cout << min(cnt[0], min(cnt[1], cnt[2])) << endl;
  return 0;
}