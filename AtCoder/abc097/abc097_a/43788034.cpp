// detail: https://atcoder.jp/contests/abc097/submissions/43788034
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (abs(a - c) <= d) {
    cout << "Yes" << endl;
    return 0;
  }

  if (a <= b and b <= c) {
    if (abs(a - b) <= d and abs(b - c) <= d) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  if (a >= b and b >= c) {
    if (abs(a - b) <= d and abs(b - c) <= d) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}
