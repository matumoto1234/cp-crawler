// detail: https://atcoder.jp/contests/abs/submissions/13443132
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n, y;
  ll a, b, c;
  cin >> n >> y;
  a = b = c = 0;
  if(y >= 10000){
    a = y / 10000;
  	y -= 10000 * a;
  }
  if(y >= 5000){
    b = y / 5000;
    y -= 5000 * b;
  }
  c = y / 1000;
  if(a + b + c > n){
  	cout << "-1 -1 -1" << endl;
  }else {
    cout << a << " " << b << " " << c << endl;
  }
  return 0;
}