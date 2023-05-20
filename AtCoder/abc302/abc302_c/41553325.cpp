// detail: https://atcoder.jp/contests/abc302/submissions/41553325
#include <bits/stdc++.h>
using namespace std;

int diff(string s, string t) {
  int dif = 0;
  int m = s.size();
  for (int i = 0; i < m; i++) {
    if (s[i] != t[i]) {
      dif++;
    }
  }

  return dif;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> s(n);
  for (auto &v: s) {
    cin >> v;
  }

  vector<int> idxs(n);
  iota(idxs.begin(), idxs.end(), 0);

  bool ans = false;

  do {
    bool invalid = false;

    for (int i = 0; i < int(idxs.size()) - 1; i++) {
      int now = idxs[i];
      int next = idxs[i + 1];

      if (diff(s[now], s[next]) != 1) {
        invalid = true;
      }
    }

    if (not invalid) {
      ans = true;
    }

  } while (next_permutation(idxs.begin(), idxs.end()));

  cout << (ans ? "Yes" : "No") << endl;
}
