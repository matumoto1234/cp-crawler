// detail: https://atcoder.jp/contests/abs/submissions/13442602
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int cnt = 0;
  cin >> s;
  for(int i = 0; i < 3; i++){
    if(s[i] == '1'){
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}