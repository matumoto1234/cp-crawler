// detail: https://atcoder.jp/contests/abc309/submissions/43339153
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if (a > b) {
    swap(a, b);
  }

  for (int i = 1; i <= 9; i++) {
    if (i % 3 == 0) {
      continue;
    }
    if (i == a and i + 1 == b) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
