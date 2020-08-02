// detail: https://atcoder.jp/contests/abc174/submissions/15596746
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n,d;
  cin >> n>>d;
  vector<ll> x(n), y(n);
  int cnt = 0;
  for (int i = 0; i < n;i++){
    cin >> x[i] >> y[i];
    if(d*d>=x[i]*x[i]+y[i]*y[i]){
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}