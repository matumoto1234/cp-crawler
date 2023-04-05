// detail: https://atcoder.jp/contests/abc100/submissions/14612713
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll powpow(ll a,ll b){
  for (ll i = 0; i < b - 1;i++){
    a *= a;
  }
  return a;
}

int main() {
  ll d, n;
  cin >> d >> n;
  ll tmp = 1, cnt = 0;
  for (ll i = 1; true;i++){
    if(i%powpow(100LL,d)==0&&d>=1){
      cnt++;
    }else if(d==0&&i%100!=0){
      cnt++;
    }
    if(cnt==n){
      tmp = i;
      break;
    }
  }
  cout << tmp << endl;
  return 0;
}