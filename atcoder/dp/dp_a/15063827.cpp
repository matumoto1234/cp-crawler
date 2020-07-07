// detail: https://atcoder.jp/contests/dp/submissions/15063827
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> h(n);
  vector<int> dp(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  dp[1] = abs(h[1] - h[0]);
  for (int i = 2; i < n; i++) {
    int tmp1 = dp[i - 1] + abs(h[i] - h[i - 1]);
    int tmp2 = dp[i - 2] + abs(h[i] - h[i - 2]);
    if (tmp1 < tmp2) {
      dp[i] = tmp1;
    } else {
      dp[i] = tmp2;
    }
  }
  printf("%d\n", dp[n - 1]);
  return 0;
}