// detail: https://atcoder.jp/contests/abc174/submissions/15698054
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

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll max_v = LLONG_MIN;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    max_v = max(a[i], max_v);
  }

  ll l = 0, r = max_v, mid = (l + r) / 2;
  while (r - l > 1) {
    // printf("l=%lld r=%lld mid=%lld func(mid)=%lld\n", l, r, mid,func(mid, n,
    // a));
    if (func(l, n, a) == k) {
      break;
    }
    if (func(r, n, a) == k) {
      l = r;
      break;
    }
    ll temp = func(mid, n, a);
    if (temp > k) {
      l = mid;
      mid = (l + r) / 2;
    } else if (temp < k) {
      r = mid;
      mid = (l + r) / 2;
    } else {
      l = mid;
      break;
    }
  }
  ll ans = l;
  for (ll i = l; func(i, n, a) == k; i--) {
    ans = i;
  }
  cout << ans << endl;
  return 0;
}