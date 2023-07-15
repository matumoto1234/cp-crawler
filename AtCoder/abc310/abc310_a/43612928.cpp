// detail: https://atcoder.jp/contests/abc310/submissions/43612928
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, p, q;
  cin >> n >> p >> q;

  vector<int> d(n);
  for (auto &v: d) {
    cin >> v;
  }

  cout << min(p, q + *min_element(d.begin(), d.end())) << endl;
}
