// detail: https://atcoder.jp/contests/abc306/submissions/42367625
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<ll> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  constexpr ll inf = 1LL << 62;

  // dp[i][0] := i番目の料理を食べたときの最大値
  // dp[i][1] := i番目の料理を下げたときの最大値
  vector<vector<ll>> dp(n + 1, vector<ll>(2, -inf));
  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    if (x[i] == 0) {
      dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + y[i]);
      dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + y[i]);
    }

    if (x[i] == 1) {
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + y[i]);
    }

    dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
    dp[i + 1][1] = max(dp[i + 1][1], dp[i][1]);
  }

  cout << max({ dp[n][0], dp[n][1], 0LL }) << endl;
}
