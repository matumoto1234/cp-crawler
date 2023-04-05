// detail: https://atcoder.jp/contests/abc063/submissions/14932978
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    sum += s[i];
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < n; i++) {
    if (sum % 10 != 0) {
      break;
    }
    if (s[i] % 10 != 0) {
      sum -= s[i];
    }
  }
  if (sum % 10 == 0) {
    cout << 0 << endl;
  } else {
    cout << sum << endl;
  }
  return 0;
}