// detail: https://atcoder.jp/contests/abc170/submissions/14292124
#include <bits/stdc++.h>
using namespace std;
int main() {
  int x,y;
  cin >> x >> y;
  bool flg = false;
  for (int i = 0; i <= x;i++){
    for (int j = 0; j <= x;j++){
      if(i*2+j*4==y){
        flg = true;
      }
    }
  }
  if(flg){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}