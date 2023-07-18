// detail: https://atcoder.jp/contests/abc179/submissions/43722250
#include <atcoder/modint>
#include <atcoder/segtree>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

mint op(mint a, mint b) {
  return a + b;
}

mint e() {
  return mint(0);
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> lr(k);
  for (auto &[l, r]: lr) {
    cin >> l >> r;
  }

  segtree<mint, op, e> dp(n);
  dp.set(0, mint(1));

  for (int i = 0; i < n; i++) {
    mint sum = dp.get(i);

    for (auto [l, r]: lr) {
      int left = i - r;
      int right = i - l;
      if (0 <= left and 0 <= right) {
        sum += dp.prod(left, right + 1);
      } else if (left < 0 and 0 <= right) {
        sum += dp.prod(0, right + 1);
      }
    }

    dp.set(i, sum);
  }

  cout << dp.get(n - 1).val() << endl;
}