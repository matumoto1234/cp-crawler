// detail: https://atcoder.jp/contests/abc304/submissions/41971888
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  ll w, h;
  cin >> w >> h;

  int n;
  cin >> n;

  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> q[i];
  }

  ll A;
  cin >> A;
  vector<int> a(A);
  for (auto &v: a) {
    cin >> v;
  }

  a.insert(a.begin(), 0);
  a.push_back(w);

  ll B;
  cin >> B;
  vector<int> b(B);
  for (auto &v: b) {
    cin >> v;
  }

  b.insert(b.begin(), 0);
  b.push_back(h);

  map<pair<int, int>, map<pair<int, int>, int>> range_to_count;

  for (int i = 0; i < n; i++) {
    int ai = upper_bound(a.begin(), a.end(), p[i]) - a.begin();
    int bi = upper_bound(b.begin(), b.end(), q[i]) - b.begin();

    int xbegin = a[ai - 1], xend = a[ai];
    int ybegin = b[bi - 1], yend = b[bi];

    range_to_count[pair(xbegin, xend)][pair(ybegin, yend)]++;
  }

  int min_ans = 1 << 30;
  int max_ans = 0;

  ll size = 0;

  for (const auto &[xrange, tmp]: range_to_count) {
    size += tmp.size();

    for (const auto &[yrange, cnt]: tmp) {
      min_ans = min(min_ans, cnt);
      max_ans = max(max_ans, cnt);
    }
  }

  if (size < (A + 1) * (B + 1)) {
    min_ans = 0;
  }

  cout << min_ans << ' ' << max_ans << endl;
}
