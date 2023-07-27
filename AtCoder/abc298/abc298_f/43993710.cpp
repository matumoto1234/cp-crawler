// detail: https://atcoder.jp/contests/abc298/submissions/43993710
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Compress {
  vector<T> xs;
  Compress() {}
  Compress(int N): xs(N, 0) {}
  Compress(const vector<T> &vs): xs(vs) {}

  void set(int i, T x) {
    xs[i] = x;
  }

  void set(const vector<T> &vs) {
    for (int i = 0; i < min<int>(xs.size(), vs.size()); i++) {
      xs[i] = vs[i];
    }
  }

  void add(T x) {
    xs.emplace_back(x);
  }

  void add(const vector<T> &vs) {
    for (const T &x: vs) {
      xs.emplace_back(x);
    }
  }

  Compress<T> build() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    return *this;
  }

  vector<T> get(const vector<T> &vs) const {
    vector<T> res = vs;
    for (T &x: res) {
      x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }
    return res;
  }

  int get(T k) const {
    return lower_bound(xs.begin(), xs.end(), k) - xs.begin();
  }

  const T &operator[](int k) const {
    return xs[k];
  }
};

#define int long long

signed main() {
  int n;
  cin >> n;

  vector<tuple<int, int, int>> rcx(n);
  for (auto &[r, c, x]: rcx) {
    cin >> r >> c >> x;
  }

  Compress<int> c_row, c_col;

  for (auto [r, c, x]: rcx) {
    c_row.add(r);
    c_row.add(r + 1);
    c_col.add(c);
    c_row.add(c + 1);
  }

  c_row.build();
  c_col.build();

  vector<int> sum_row(10 * n, 0), sum_col(10 * n, 0);
  for (auto [r, c, x]: rcx) {
    int ri = c_row.get(r);
    sum_row[ri] += x;

    int ci = c_col.get(c);
    sum_col[ci] += x;
  }

  map<pair<int, int>, int> rc_to_x;
  for (auto [r, c, x]: rcx) {
    rc_to_x[pair(r, c)] = x;
  }

  int ans = -(1LL << 60);
  for (auto [r, c, x]: rcx) {
    int ri = c_row.get(r);
    int ci = c_col.get(c);
    ans = max(ans, sum_row[ri] + sum_col[ci] - x);

    int ri2 = c_row.get(r + 1);
    int ci2 = c_col.get(c + 1);
    ans = max(ans, sum_row[ri2] + sum_col[ci2] - rc_to_x[pair(r + 1, c + 1)]);
  }

  cout << ans << endl;
}
