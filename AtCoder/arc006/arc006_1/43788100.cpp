// detail: https://atcoder.jp/contests/arc006/submissions/43788100
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> e(6);
  for (auto &v: e) {
    cin >> v;
  }

  int b;
  cin >> b;

  vector<int> l(6);
  for (auto &v: l) {
    cin >> v;
  }

  vector<int> intersection;
  set_intersection(e.begin(), e.end(), l.begin(), l.end(), back_inserter(intersection));

  vector<int> diff;
  switch (intersection.size()) {
    case 6:
      cout << 1 << endl;
      break;
    case 5:
      set_difference(l.begin(), l.end(), intersection.begin(), intersection.end(), back_inserter(diff));
      if (diff[0] == b) {
        cout << 2 << endl;
      } else {
        cout << 3 << endl;
      }
      break;
    case 4:
      cout << 4 << endl;
      break;
    case 3:
      cout << 5 << endl;
      break;
    default:
      cout << 0 << endl;
  }
}
