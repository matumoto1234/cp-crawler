// detail: https://atcoder.jp/contests/abc174/submissions/15698285
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int kiriage(double a) {
  if (a - (int)a == 0) {
    return (int)a;
  } else {
    return (int)a + 1;
  }
}

ll func(int x, int n, vector<ll> a) {
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += kiriage((double)a[i] / (double)x) - 1;
  }
  return sum;
}

int main(int argc,char *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll l = 0, r = 1e9, ans;
  while (l <= r) {
    ll mid = (l + r) / 2;
    ll temp = func(mid, n, a);
    if (temp <= k) {
      ans = mid;
      r = mid - 1;
    }
    else
      l = mid + 1;
  }
  cout << ans << endl;
  return 1;
}