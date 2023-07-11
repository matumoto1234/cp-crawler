// detail: https://atcoder.jp/contests/abc285/submissions/43488600
#include <bits/stdc++.h>
using namespace std;

using ll = long long;



ll convert_base(string s) {
  ll pow = 1;
  ll sum = 0;
  for (int i = (int)s.size() - 1; i >= 0; i--) {
    ll diff = s[i] - 'A';
    sum += (diff + 1) * pow;
    pow *= 26;
  }
  return sum;
}

int main() {
  string s;
  cin >> s;

  cout << convert_base(s) << endl;
}
