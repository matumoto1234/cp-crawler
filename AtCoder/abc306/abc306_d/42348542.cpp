// detail: https://atcoder.jp/contests/abc306/submissions/42348542
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> split(const vector<pair<int, int>> &xy, int target) {
  vector<vector<pair<int, int>>> xys(1);

  for (size_t i = 0; i < xy.size(); i++) {
    const auto &[x, y] = xy[i];

    xys.back().push_back(xy[i]);

    if (x == target and i < xy.size() - 1) {
      xys.push_back(vector<pair<int, int>>());
    }
  }

  return xys;
}

using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> xy(n);
  for (int i = 0; i < n; i++) {
    auto &[x, y] = xy[i];
    cin >> x >> y;
  }

  xy.push_back(pair(0, 0));

  vector<vector<pair<int, int>>> splitted = split(xy, 0);

  ll sum = 0;

  for (auto xys: splitted) {
    int mx = 0;

    int detox = xys.back().second;
    xys.pop_back();

    for (auto [x, y]: xys) {
      assert(x == 1);
      mx = max(mx, y);
    }

    if (mx + detox < 0) {
      continue;
    }

    sum += mx + detox;
  }


  cout << sum << endl;
}