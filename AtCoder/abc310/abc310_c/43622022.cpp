// detail: https://atcoder.jp/contests/abc310/submissions/43622022
#include <bits/stdc++.h>
using namespace std;

string reversed(string s) {
  reverse(s.begin(), s.end());
  return s;
}

int main() {
  int n;
  cin >> n;

  vector<string> s(n);
  for (auto &v: s) {
    cin >> v;

    if (v > reversed(v)) {
      v = reversed(v);
    }
  }

  sort(s.begin(), s.end());

  int cnt = 1;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1] or reversed(s[i]) == s[i + 1] or s[i] == reversed(s[i + 1])) {
      continue;
    }
    cnt++;
  }

  cout << cnt << endl;
}
