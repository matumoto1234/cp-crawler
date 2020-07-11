// detail: https://atcoder.jp/contests/dp/submissions/15137132
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  vector<int> dp(n, INT_MAX);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k && i + j < n; j++) {
      int tmp = abs(h[i + j] - h[i]);
      if (dp[i] + tmp < dp[i + j]) {
        dp[i + j] = dp[i] + tmp;
      }
    }
  }
  cout << dp[n - 1] << endl;
  return 0;
}