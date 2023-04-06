// detail: https://atcoder.jp/contests/abc173/submissions/15007719
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll ans = 0, n, minf=LLONG_MAX;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i];
    minf = min(a[i], minf);
  }
  ans -= minf;
  cout << ans << endl;
  return 0;
}