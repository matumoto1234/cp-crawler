// detail: https://atcoder.jp/contests/abc306/submissions/42321038
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  vector<ll> a(64);
  for (auto &v: a) {
    cin >> v;
  }

  unsigned long long sum = 0;
  for (int i = 0; i < 64; i++) {
    sum += a[i] * (1LL << i);
  }

  cout << sum << endl;
}