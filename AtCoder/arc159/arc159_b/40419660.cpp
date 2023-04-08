// detail: https://atcoder.jp/contests/arc159/submissions/40419660
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll naive_solve(ll a, ll b) {
  int cnt = 0;
  while (a >= 1 and b >= 1) {
    ll g = gcd(a, b);
    a -= g;
    b -= g;
    cnt++;
  }

  return cnt;
}

int main() {
  ll a, b;
  cin >> a >> b;

  cout << naive_solve(a, b) << endl;

  // for (int a = 0; a <= 10; a++) {
  //   for (int b = 0; b <= 10; b++) {
  //     int ans = naive_solve(a, b);

  //     cout << "a:" << a << " b:" << b << " ans:" << ans << endl;
  //   }
  // }
}
