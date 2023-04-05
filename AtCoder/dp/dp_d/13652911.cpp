// detail: https://atcoder.jp/contests/dp/submissions/13652911
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> w(100), v(100);
  vector<vector<ll>> dp(101, vector<ll>(m + 1, 0));

  for (ll i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j <= m; j++) {
      if (j - w[i] >= 0) {
        if (dp[i][j] > dp[i][j - w[i]] + v[i]) {
          dp[i + 1][j] = dp[i][j];
        } else {
          dp[i + 1][j] = dp[i][j - w[i]] + v[i];
        }
      }else{
        dp[i + 1][j] = dp[i][j];
      }
    }
  }
  /*
  for (ll i = 0; i <= n; i++) {
    for (ll j = 0; j <= m; j++) {
      cout << dp[i][j] << " " << flush;
    }
    cout << endl;
  }*/
  cout << dp[n][m] << endl;
  return 0;
}