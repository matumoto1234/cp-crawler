// detail: https://atcoder.jp/contests/nomura2020/submissions/13721905
#include<bits/stdc++.h>
using namespace std;
int main(){
  string t;
  int ans = 0;

  cin >> t;
  for (int i = 0; i < t.size() - 1;i++){
    if(t[i]=='?'){
      if (t[i + 1] == 'P') {
        t[i] = 'D';
      } else {
        t[i] = 'P';
      }
    }
  }
  if(t[t.size()-1]=='?'){
    t[t.size()-1] = 'D';
  }
  cout << t << endl;
  return 0;
}