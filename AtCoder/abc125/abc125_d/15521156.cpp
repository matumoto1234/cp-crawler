// detail: https://atcoder.jp/contests/abc125/submissions/15521156
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll absll(ll a){
  if(a<0){
    return a * -1;
  }
  return a;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n+1,0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll sum = 0;
  for (ll i = 0; i < n-1; i++) {
    if(a[i]<0){
      sum += a[i] * -1;
      a[i + 1] *= -1;
    }else{
      sum += a[i];
    }
  }
  if(a[n-1]<0&&absll(a[n-1])>absll(a[n-2])){
    sum -= absll(a[n - 2])*2;
    sum += absll(a[n - 1]);
  }else{
    sum += a[n - 1];
  }
  cout << sum << endl;
  return 0;
}