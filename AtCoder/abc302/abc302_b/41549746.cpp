// detail: https://atcoder.jp/contests/abc302/submissions/41549746
#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  for (auto &v: s) {
    cin >> v;
  }

  constexpr int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
  constexpr int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

  auto is_inside = [&](int y, int x) -> bool {
    return 0 <= y and y < h and 0 <= x and x < w;
  };

  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      for (int d = 0; d < 8; d++) {
        int ny = y;
        int nx = x;
        string v = "";
        vector<pair<int, int>> ps;

        for (int k = 0; k < 5; k++) {
          if (not is_inside(ny, nx)) {
            continue;
          }

          v += s[ny][nx];
          ps.emplace_back(ny, nx);

          ny += dy[d];
          nx += dx[d];
        }

        if (v == "snuke") {
          for (auto [r, c]: ps) {
            cout << r + 1 << " " << c + 1 << "\n";
          }
          return 0;
        }
      }
    }
  }
}