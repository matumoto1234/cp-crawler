// detail: https://atcoder.jp/contests/abc003/submissions/43770517
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> r(n);
  for (auto &v: r) {
    cin >> v;
  }

  sort(r.rbegin(), r.rend());

  vector<int> vs(r.begin(), r.begin() + k);
  sort(vs.begin(), vs.end());

  double rate = 0;
  for (auto v: vs) {
    rate = (v + rate) / 2.0;
  }

  cout << fixed << setprecision(10) << rate << endl;
}
