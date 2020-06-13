// detail: https://atcoder.jp/contests/abc134/submissions/14264481
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n), cp(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cp[i] = a[i];
  }
  sort(cp.begin(), cp.end());
  for (int i = 0; i < n; i++) {
    if (cp[n - 1] == a[i]) {
      cout << cp[n - 2] << endl;
    } else {
      cout << cp[n - 1] << endl;
    }
  }
  return 0;
}