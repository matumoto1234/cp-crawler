// detail: https://atcoder.jp/contests/code-festival-2014-quala/submissions/41339623
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  // [a,b] - [0,a)

  a--;
  int since = a / 4 - a / 100 + a / 400;
  int to = b / 4 - b / 100 + b / 400;

  cout << to - since << endl;
}
