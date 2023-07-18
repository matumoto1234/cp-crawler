// detail: https://atcoder.jp/contests/tenka1-2014-qualb/submissions/43722932
#include <atcoder/modint>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<string> t(n);
  for (auto &v: t) {
    cin >> v;
  }

  vector<mint> dp(s.size() + 1);
  dp[0] = 1;
  for (int i = 0; i < (int)s.size(); i++) {
    for (int j = 0; j < n; j++) {
      if (s.substr(i, t[j].size()) == t[j]) {
        dp[i + t[j].size()] += dp[i];
      }
    }
  }

  cout << dp[s.size()].val() << endl;
}
