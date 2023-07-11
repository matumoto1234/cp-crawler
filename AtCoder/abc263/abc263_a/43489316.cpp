// detail: https://atcoder.jp/contests/abc263/submissions/43489316
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;

  map<int, int> counter;
  counter[a]++;
  counter[b]++;
  counter[c]++;
  counter[d]++;
  counter[e]++;

  vector<pair<int, int>> entries;
  for (auto p: counter) {
    entries.push_back(p);
  }

  cout << ((int)entries.size() >= 2 and ((entries[0].second == 2 and entries[1].second == 3) or (entries[0].second == 3 and entries[1].second == 2)) ? "Yes" : "No") << endl;
}
