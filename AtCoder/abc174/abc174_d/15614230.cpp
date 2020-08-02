// detail: https://atcoder.jp/contests/abc174/submissions/15614230
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int wcnt = 0, rcnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'W'&&i<n/2) {
      wcnt++;
    }else if(s[i]=='R'){
      rcnt++;
    }
  }
  cout << min(wcnt, rcnt) << endl;
}