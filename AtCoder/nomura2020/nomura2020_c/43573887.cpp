// detail: https://atcoder.jp/contests/nomura2020/submissions/43573887
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename T>
struct CumulativeSum {
  vector<T> data;
  CumulativeSum(int n): data(n + 1, 0) {}
  CumulativeSum(int n, T x): data(n + 1, x) {}

  void set(int k, T x) {
    data[k + 1] = x;
  }

  void add(int k, T x) {
    data[k + 1] = x;
  }

  T get(int k) {
    return data[k + 1];
  }

  void build() {
    for (int i = 0; i < static_cast<int>(data.size()) - 1; i++) {
      data[i + 1] += data[i];
    }
  }

  // [l,r)
  T query(int l, int r) {
    return data[r] - data[l];
  }
};

int main() {
  int n;
  cin >> n;

  vector<ll> a(n + 1);
  for (auto &v: a) {
    cin >> v;
  }

  if (a[0] > 1) {
    cout << -1 << endl;
    return 0;
  }


  CumulativeSum<ll> cs(a.size());
  for (int i = 0; i < (int)a.size(); i++) {
    cs.set(i, a[i]);
  }

  cs.build();

  vector<ll> b(a.size(), 0);
  b[0] = 1 - a[0];
  for (int i = 1; i < (int)b.size(); i++) {
    ll v1 = 2 * b[i - 1] - a[i];
    ll v2 = cs.query(i + 1, a.size());
    b[i] = min(v1, v2);
    if (b[i] < 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << accumulate(a.begin(), a.end(), 0LL) + accumulate(b.begin(), b.end(), 0LL) << endl;
}
