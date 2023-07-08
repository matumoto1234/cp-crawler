// detail: https://atcoder.jp/contests/abc309/submissions/43391290
#include <bits/stdc++.h>
using namespace std;

bool is_valid(tuple<int, int, int> a, tuple<int, int, int> b) {
  auto [a1, a2, a3] = a;
  auto [b1, b2, b3] = b;

  vector<int> aa = { a1, a2, a3 };
  vector<int> bb = { b1, b2, b3 };

  vector<int> ai(3);
  iota(ai.begin(), ai.end(), 0);

  vector<int> bi(3);
  iota(bi.begin(), bi.end(), 0);

  do {
    do {
      if (aa[ai[0]] < bb[bi[0]] and aa[ai[1]] < bb[bi[1]] and aa[ai[2]] < bb[bi[2]]) {
        return true;
      }
    } while (next_permutation(bi.begin(), bi.end()));
  } while (next_permutation(ai.begin(), ai.end()));

  return false;
}

int main() {
  int n;
  cin >> n;

  vector<tuple<int, int, int>> hwd(n);
  for (auto &[h, w, d]: hwd) {
    cin >> h >> w >> d;
  }

  sort(hwd.begin(), hwd.end());
  hwd.erase(unique(hwd.begin(), hwd.end()), hwd.end());

  n = hwd.size();

  for (int i = 0; i < min(n, 5000); i++) {
    for (int j = min(n, 5000) - 1; j > i; j--) {
      if (i != j and is_valid(hwd[i], hwd[j])) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
