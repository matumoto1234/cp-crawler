// detail: https://atcoder.jp/contests/abc309/submissions/43356082
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

namespace matumoto {
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
} // namespace matumoto

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> ab(n);
  for (auto &[a, b]: ab) {
    cin >> a >> b;
  }

  sort(ab.begin(), ab.end());

  ll all_sum = 0;
  for (auto [a, b]: ab) {
    all_sum += b;
  }

  matumoto::CumulativeSum<ll> cs(n);
  for (int i = 0; i < n; i++) {
    auto [a, b] = ab[i];
    cs.set(i, b);
  }

  cs.build();

  ll valid = 2e9;
  ll invalid = 0;

  auto is_valid = [&](ll d) -> bool {
    int idx = lower_bound(ab.begin(), ab.end(), pair<int, int>(d, 0)) - ab.begin();
    return all_sum - cs.query(0, idx) <= k;
  };

  while (abs(valid - invalid) > 1) {
    ll mid = (valid + invalid) / 2;
    if (is_valid(mid)) {
      valid = mid;
    } else {
      invalid = mid;
    }
  }

  cout << valid << endl;
}
