// detail: https://atcoder.jp/contests/abc253/submissions/39337926
#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;

  map<int, int> counter;
  for (int _ = 0; _ < q; _++) {
    int order;
    cin >> order;

    if (order == 1) {
      int x;
      cin >> x;
      counter[x]++;
      continue;
    }
    if (order == 2) {
      int x, c;
      cin >> x >> c;
      counter[x] -= min(c, counter[x]);
      if (counter[x] == 0) {
        counter.erase(x);
      }
      continue;
    }
    if (order == 3) {
      int min = counter.begin()->first;
      int max = counter.rbegin()->first;
      cout << max - min << "\n";
      continue;
    }
  }
}
