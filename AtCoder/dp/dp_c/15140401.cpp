// detail: https://atcoder.jp/contests/dp/submissions/15140401
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(3));
  vector<vector<int>> dp(n, vector<int>(3, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
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
  } /*
   for (int i = 0; i <= n;i++){
     for (int j = 0; j < 3; j++){
       printf("%d ", dp[i][j]);
     }
     cout << endl;
   }*/
  cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;
  return 0;
}