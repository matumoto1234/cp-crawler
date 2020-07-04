// detail: https://atcoder.jp/contests/panasonic2020/submissions/14933368
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll a, b, c;
  cin >> a >> b >> c;
  //cout << (a + b - c) * (a + b - c) << endl;
  //cout << 4LL * a * b << endl;
  if ((a + b - c) * (a + b - c) > 4LL * a * b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  /*√a+√b<√c
  =(√a+√b)^2<c
  =a+2√ab+b<c
  =a+b-c<-2√ab
  =(a+b-c)^2>4ab
  */
  return 0;
}