// detail: https://atcoder.jp/contests/abc146/submissions/15224256
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, x;
ll nibun(ll upper, ll lower, ll mid) {
  ll tmp = mid * a + b * (ll)log10l(mid);
  //cout << tmp << " " << upper << " " << lower << " " << mid << endl;
  if (upper < lower) {
    return 0;
  }else if(upper==lower){
    if(tmp>x){
      ll i;
      for (i = upper; tmp > x;i--){
        tmp = i * a + b * (ll)log10l(i);
        //cout << tmp << endl;
      }
      return i;
    }else{
      ll i;
      for (i = lower; tmp < x;i++){
        tmp = i * a + b * (ll)log10l(i);
        //cout << tmp << endl;
      }
      return i;
    }
  }
  if (tmp > x) {
    return nibun(mid - 1, lower, (mid - 1 + lower) / 2);
  } else if (tmp < x) {
    return nibun(upper, mid + 1, (upper + mid + 1) / 2);
  } else {
    return mid;
  }
}

int main() {
  cin >> a >> b >> x;
  cout << (long long)nibun(1000000000, 1, 1000000001 / 2) << endl;
  return 0;
}