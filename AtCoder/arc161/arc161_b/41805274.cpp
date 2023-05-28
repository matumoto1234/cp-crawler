// detail: https://atcoder.jp/contests/arc161/submissions/41805274
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int f(ll x) {
  return bitset<64>(x).count();
}

void solve() {
  ll n;
  cin >> n;

  if (n < 8) {
    cout << -1 << "\n";
    return;
  }

  constexpr int size = 64;
  bitset<size> bits(n);

  if (bits.count() >= 3) {
    bitset<size> ans;

    for (int i = size - 1; i >= 0; i--) {
      if (bits[i]) {
        ans[i] = 1;
      }
      if (ans.count() == 3) {
        break;
      }
    }

    cout << ans.to_ullong() << "\n";
    return;
  }

  // most significant bit
  int msb = 0;
  for (int i = size - 1; i >= 0; i--) {
    if (bits[i]) {
      msb = i;
      break;
    }
  }

  bitset<size> ans;
  for (int i = 1; i <= 3; i++) {
    ans[msb - i] = 1;
  }

  cout << ans.to_ullong() << "\n";
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}
