// detail: https://atcoder.jp/contests/abc259/submissions/39557965
#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> runlength(string s) {
  vector<pair<char, int>> res;
  for (auto c: s) {
    if (res.empty() or res.back().first != c) {
      res.push_back({ c, 1 });
    } else {
      res.back().second++;
    }
  }
  return res;
}

int main() {
  string s, t;
  cin >> s >> t;

  auto s2 = runlength(s);
  auto t2 = runlength(t);

  for (int i = 0; i < int(s2.size()); i++) {
    auto [s_ch, s_cnt] = s2[i];
    auto [t_ch, t_cnt] = t2[i];
    if (s_ch != t_ch) {
      cout << "No" << endl;
      return 0;
    }

    if (s_cnt < t_cnt and s_cnt == 1) {
      cout << "No" << endl;
      return 0;
    }

    if (s_cnt > t_cnt) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
