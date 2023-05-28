// detail: https://atcoder.jp/contests/arc161/submissions/41809036
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int f(ll x) {
  return bitset<64>(x).count();
}

void solve() {
  ll n;
  cin >> n;

  if (n < 7) {
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

    assert(ans.count() == 3);

    cout << ans.to_ullong() << "\n";
    return;
  }

  if (bits.count() == 1) {
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

    assert(ans.count() == 3);

    cout << ans.to_ullong() << "\n";
    return;
  }

  assert(bits.count() == 2);

  int msb = -1;
  int msb2 = -1;
  for (int i = size - 1; i >= 0; i--) {
    if (bits[i] and msb == -1) {
      msb = i;
      continue;
    }

    if (bits[i] and msb != -1) {
      msb2 = i;
      break;
    }
  }

  if (msb2 >= 2) {
    bitset<size> ans;
    ans[msb] = 1;

    for (int i = 1; i <= 2; i++) {
      ans[msb2 - i] = 1;
    }

    assert(ans.count() == 3);

    cout << ans.to_ullong() << "\n";
    return;
  }

  bitset<size> ans;
  for (int i = 1; i <= 3; i++) {
    ans[msb - i] = 1;
  }

  assert(ans.count() == 3);

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
