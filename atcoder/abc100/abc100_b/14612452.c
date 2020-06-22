// detail: https://atcoder.jp/contests/abc100/submissions/14612452
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll d, n;
  cin >> d >> n;
  ll tmp = 1;
  for (int i = 0; i < d; i++) {
    tmp *= 100;
  }
  if(d==0&&n==100){
    cout << 101 << endl;
  }
  else{
    cout << tmp * n << endl;
  }
  return 0;
}