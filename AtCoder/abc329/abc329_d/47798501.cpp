// detail: https://atcoder.jp/contests/abc329/submissions/47798501
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  for (auto &v : a) {
    cin >> v;
    v--;
  }

  vector<int> cnt(n + 1, 0);
  int ans = 0;

  for (auto v : a) {
    cnt[v]++;

    if (cnt[ans] < cnt[v]) {
      ans = v;
    } else if (cnt[ans] == cnt[v]) {
      ans = min(ans, v);
    }

    cout << ans + 1 << "\n";
  }
}
