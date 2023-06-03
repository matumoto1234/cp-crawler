// detail: https://atcoder.jp/contests/abc304/submissions/41938318
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n < 1000) {
    cout << n << endl;
    return 0;
  }

  string s = to_string(n);

  cout << ""s + s[0] + s[1] + s[2] + string(s.size() - 3, '0') << endl;
}
