// detail: https://atcoder.jp/contests/abc249/submissions/43537314
#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, int c, int x) {
  int meter = 0;
  int t = 0;
  while (t < x) {
    int rem = x - t;
    if (rem < a) {
      meter += rem * b;
      t += rem;
      break;
    } else {
      meter += a * b;
      t += a;
    }

    rem = x - t;
    if (rem < c) {
      t += rem;
      break;
    } else {
      t += c;
    }
  }
  return meter;
}

int main() {
  int a, b, c, d, e, f, x;
  cin >> a >> b >> c >> d >> e >> f >> x;

  if (solve(a, b, c, x) < solve(d, e, f, x)) {
    cout << "Aoki" << endl;
  } else if (solve(a, b, c, x) == solve(d, e, f, x)) {
    cout << "Draw" << endl;
  } else {
    cout << "Takahashi" << endl;
  }
}
