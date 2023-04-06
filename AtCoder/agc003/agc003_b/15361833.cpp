// detail: https://atcoder.jp/contests/agc003/submissions/15361833
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n;i++){
    cin >> a[i];
  }
  ll ans = 0;
  if(n==1){
    ans += a[0] / 2LL;
  }
  for (int i = 0; i < n - 1;i++){
    if(a[i]>a[i+1]){
      ans += a[i + 1];
      a[i] -= a[i + 1];
      a[i + 1] = 0;
      ans += a[i] / 2;
    }else{
      ans += a[i];
      a[i + 1] -= a[i];
      a[i] = 0;
    }
    if(i==n-2){
      ans += a[i + 1] / 2;
    }
  }
  cout << ans << endl;
  return 0;
}