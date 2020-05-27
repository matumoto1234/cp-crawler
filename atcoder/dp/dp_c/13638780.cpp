// detail: https://atcoder.jp/contests/dp/submissions/13638780
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(3));
  vector<vector<int>> dp(n + 1, vector<int>(3, 0));

  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  dp[0][0] = a[0][0];
  dp[0][1] = a[0][1];
  dp[0][2] = a[0][2];
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j == k) {
          continue;
        }
        if (dp[i][j] + a[i + 1][k] > dp[i + 1][k]) {
          dp[i + 1][k] = dp[i][j] + a[i + 1][k];
        }
      }
    }
  }
  int x, y, z;
  x = dp[n - 1][0];
  y = dp[n - 1][1];
  z = dp[n - 1][2];
  cout << max({x, y, z}) << endl;
  /*for (int i = 0; i < n;i++){
    cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
  }*/
  return 0;
}