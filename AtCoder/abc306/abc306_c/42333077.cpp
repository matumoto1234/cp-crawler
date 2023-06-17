// detail: https://atcoder.jp/contests/abc306/submissions/42333077
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(3 * n);
  for (auto &v: a) {
    cin >> v;
  }

  map<int, vector<int>> to_indexes;

  for (int i = 0; i < 3 * n; i++) {
    to_indexes[a[i]].push_back(i);
  }

  vector<pair<int, int>> ps;
  ps.reserve(n);

  for (auto &[ai, indexes]: to_indexes) {
    sort(indexes.begin(), indexes.end());
    ps.push_back(pair(indexes[1], ai));
  }

  sort(ps.begin(), ps.end());

  for (size_t i = 0; i < ps.size(); i++) {
    if (i) {
      cout << " ";
    }

    int ai = ps[i].second;
    cout << ai;
  }
  cout << endl;
}
