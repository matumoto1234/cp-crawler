// detail: https://atcoder.jp/contests/abc012/submissions/43558802
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int h = n / 3600;
  int m = n % 3600 / 60;
  int s = n % 60;

  printf("%02d:%02d:%02d\n", h, m, s);
}
