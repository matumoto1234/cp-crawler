// detail: https://atcoder.jp/contests/abc112/submissions/15257456
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n, m, sum, ans = 1;
  cin >> n >> m;
  for (ll i = 1; n * i <= m;i++){
    sum = m - n * i;
    if(sum%i==0){
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}