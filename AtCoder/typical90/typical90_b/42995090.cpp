// detail: https://atcoder.jp/contests/typical90/submissions/42995090
#include <bits/stdc++.h>
using namespace std;

bool is_valid(string s) {
  int open = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '(') {
      open++;
      continue;
    }

    if (open == 0) {
      return false;
    }

    open--;
  }

  return open == 0;
}

int main() {
  int n;
  cin >> n;

  for (int bit = 0; bit < (1 << n); bit++) {
    string s = "";
    for (int i = 0; i < n; i++) {
      if (bit >> i & 1) {
        s += "(";
      } else {
        s += ")";
      }
    }

    if (is_valid(s)) {
      cout << s << "\n";
    }
  }
}