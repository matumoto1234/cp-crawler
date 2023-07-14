// detail: https://atcoder.jp/contests/abc309/submissions/43558681
#include <bits/stdc++.h>
using namespace std;

#include "atcoder/segtree"
using namespace atcoder;

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

int op(int a, int b) {
  return min(a, b);
}

int e() {
  return (1 << 30);
}

int main() {
  int n;
  cin >> n;

  vector<array<int, 3>> hwd(n);
  vector<array<int, 3>> hwd6;
  hwd6.reserve(6 * n);
  for (auto &v: hwd) {
    auto &[h, w, d] = v;
    cin >> h >> w >> d;

    std::sort(v.begin(), v.end());

    do {
      hwd6.push_back(array<int, 3>{ v[0], v[1], v[2] });
    } while (next_permutation(v.begin(), v.end()));
  }

  std::sort(hwd6.begin(), hwd6.end(), [](array<int, 3> a, array<int, 3> b) -> bool {
    auto [h1, w1, d1] = a;
    auto [h2, w2, d2] = b;

    if (h1 == h2) {
      return w1 > w2;
    }
    return h1 < h2;
  });

  Compress<int> cw;

  for (auto [_, w, __]: hwd6) {
    cw.add(w);
  }

  cw.build();

  segtree<int, op, e> seg(6 * n);

  for (auto [_, w, d]: hwd6) {
    int wi = cw.get(w);

    if (seg.prod(0, wi) < d) {
      cout << "Yes" << endl;
      return 0;
    } else {
      seg.set(wi, d);
    }
  }

  cout << "No" << endl;
}
