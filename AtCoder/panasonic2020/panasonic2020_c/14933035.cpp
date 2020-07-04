// detail: https://atcoder.jp/contests/panasonic2020/submissions/14933035
#include<bits/stdc++.h>
using namespace std;
using ld = long double;
int main(){
  ld a, b, c;
  cin >> a >> b >> c;
  if(sqrtl(a)+sqrtl(b)<sqrtl(c)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}