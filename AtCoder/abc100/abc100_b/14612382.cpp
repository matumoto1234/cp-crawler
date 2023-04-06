// detail: https://atcoder.jp/contests/abc100/submissions/14612382
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll d, n;
  cin >> d >> n;
  ll tmp = 1;
  for (int i = 0; i < d; i++) {
    tmp *= 100;
  }
  cout << tmp * n << endl;
  return 0;
}