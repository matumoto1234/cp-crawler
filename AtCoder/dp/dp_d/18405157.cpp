// detail: https://atcoder.jp/contests/dp/submissions/18405157
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, W;
  cin >> N >> W;

  vector<int> w(N), v(N);
  for (int i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
  }

  vector<ll> dp(W + 1, 0);
  for (int i = 0; i < N; i++) {
    for (int j = W; j >= w[i]; j--) {
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }

  cout << dp[W] << endl;

  return 0;
}
