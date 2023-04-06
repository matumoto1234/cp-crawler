// detail: https://atcoder.jp/contests/tokiomarine2020/submissions/14230759
#include <bits/stdc++.h>
using namespace std;
int main() {
  long long inta, b, v, w, t;
  cin >> a >> v >> b >> w >> t;
  if (a < b) {
    long long inttmp1 = t * v + a;
    long long inttmp2 = t * w + b;
    if (tmp1 >= tmp2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    long long inttmp1 = -1 * (t * v) + a;
    long long inttmp2 = -1 * (t * w) + b;
    if (tmp1 <= tmp2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}