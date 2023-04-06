// detail: https://atcoder.jp/contests/abc172/submissions/14739380
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n, m, k, cnt = 0LL, sum = 0LL;
  cin >> n >> m >> k;
  vector<ll> a(n), b(m);
  ll ai = 0LL, bi = 0LL;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  while (!a.empty() || !b.empty()) {
    if (a[ai] > b[bi]) {
      sum += b[bi++];
      if (sum > k) {
        break;
      }
      cnt++;
    } else {
      sum += a[ai++];
      if (sum > k) {
        break;
      }
      cnt++;
    }
  }
  if(a.empty()){
    while(!b.empty()){
      sum += b[bi++];
      if(sum>k){
        break;
      }
      cnt++;
    }
  }else{
    while(!a.empty()){
      sum += a[ai++];
      if(sum>k){
        break;
      }
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}