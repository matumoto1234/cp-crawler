// detail: https://atcoder.jp/contests/abc016/submissions/43558763
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if (a + b == c and a - b == c) {
    cout << "?" << endl;
  } else if (a + b == c) {
    cout << "+" << endl;
  } else if (a - b == c) {
    cout << "-" << endl;
  } else {
    cout << "!" << endl;
  }
}
