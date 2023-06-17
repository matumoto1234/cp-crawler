// detail: https://atcoder.jp/contests/abc306/submissions/42369238
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int k;
ll sum = 0;

void balance(multiset<int> &X, multiset<int> &Y) {
  while (int(X.size()) < k and not Y.empty()) {
    auto yi = prev(Y.end());

    X.insert(*yi);
    sum += *yi;

    Y.erase(yi);
  }

  while (true) {
    auto xi = X.begin();
    auto yi = prev(Y.end());

    if (*xi >= *yi) {
      break;
    }

    X.insert(*yi);
    sum += *yi;
    Y.insert(*xi);
    sum -= *xi;

    X.erase(xi);
    Y.erase(yi);
  }
}

void add(multiset<int> &X, multiset<int> &Y, int v) {
  Y.insert(v);
  balance(X, Y);
}

void erase(multiset<int> &X, multiset<int> &Y, int v) {
  auto xi = X.find(v);
  if (xi != X.end()) {
    sum -= v;
    X.erase(xi);
  } else {
    Y.erase(Y.find(v));
  }
  balance(X, Y);
}

int main() {
  int n, q;
  cin >> n >> k >> q;

  multiset<int> X, Y;
  for (int i = 0; i < k; i++) {
    X.insert(0);
  }

  for (int i = 0; i < n - k; i++) {
    Y.insert(0);
  }

  vector<int> a(n, 0);

  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;

    x--;

    add(X, Y, y);
    erase(X, Y, a[x]);

    a[x] = y;

    cout << sum << "\n";
  }
}
