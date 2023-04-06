// detail: https://atcoder.jp/contests/abc174/submissions/15620763
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int wcnt = 0, rcnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'W') {
      wcnt++;
    }else if(s[i]=='R'&&wcnt>0){
      rcnt++;
    }
  }
  int mid = min(wcnt,rcnt);
  wcnt = 0;
  for (int i = 0; i < mid;i++){
    if(s[i]=='W'){
      wcnt++;
    }
  }

    cout << min(wcnt, rcnt) << endl;
}