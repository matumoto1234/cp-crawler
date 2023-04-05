// detail: https://atcoder.jp/contests/abc063/submissions/15360563
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  bool flg = false;
  for (int i = 1; i < s.size();i++){
    if(s[i]!=s[i-1]){
      flg = true;
    }
  }
  if(flg){
    cout << "yes" << endl;
  }else{
    cout << "no" << endl;
  }
  return 0;
}