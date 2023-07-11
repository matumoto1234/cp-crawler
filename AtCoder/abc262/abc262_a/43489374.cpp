// detail: https://atcoder.jp/contests/abc262/submissions/43489374
#include <bits/stdc++.h>
using namespace std;

int main() {
  int y;
  cin >> y;

  cout << y + ((2 - y % 4) + 4) % 4 << endl;
}
