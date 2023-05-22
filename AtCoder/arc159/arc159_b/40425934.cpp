// detail: https://atcoder.jp/contests/arc159/submissions/40425934
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int a, b;
  cin >> a >> b;

  if (a < b) {
    swap(a, b);
  }

  if (a == b) {
    cout << a << endl;
    return 0;
  }

  if (a - b == 1) {
    cout << b - 1 << endl;
    return 0;
  }

  int cnt = 0;
  int g = gcd(a, b);
  while (true) {
    g = gcd(a, b);
    if (g >= (a - g) - (b - g)) {
      break;
    }

    a -= g;
    b -= g;
    cnt++;
  }

  cnt += (b + g - 1) / g;

  cout << cnt << endl;
}