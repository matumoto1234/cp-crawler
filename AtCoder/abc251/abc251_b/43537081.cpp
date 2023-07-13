// detail: https://atcoder.jp/contests/abc251/submissions/43537081
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, w;
  cin >> n >> w;

  vector<int> a(n);
  for (auto &v: a) {
    cin >> v;
  }

  vector<int> cnt(2e6, 0);

  for (int i = 0; i < n; i++) {
    if (a[i] < (int)cnt.size()) {
      cnt[a[i]]++;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[i] + a[j] < (int)cnt.size()) {
        cnt[a[i] + a[j]]++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; k++) {
        if (a[i] + a[j] + a[k] < (int)cnt.size()) {
          cnt[a[i] + a[j] + a[k]]++;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= w; i++) {
    if (cnt[i] >= 1) {
      ans++;
    }
  }
  cout << ans << endl;
}
