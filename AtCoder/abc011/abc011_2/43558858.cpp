// detail: https://atcoder.jp/contests/abc011/submissions/43558858
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  string t = ""s + (char)toupper(s[0]);
  for (int i = 1; i < (int)s.size(); i++) {
    t += (char)tolower(s[i]);
  }

  cout << t << endl;
}
