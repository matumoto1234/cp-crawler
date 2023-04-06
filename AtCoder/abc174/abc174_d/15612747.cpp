// detail: https://atcoder.jp/contests/abc174/submissions/15612747
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int wcnt = 0;
  for (int i = 0; i < n/2; i++) {
    if (s[i] == 'W') {
      wcnt++;
    }
  }
  cout << wcnt << endl;
}