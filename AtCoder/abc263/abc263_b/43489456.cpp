// detail: https://atcoder.jp/contests/abc263/submissions/43489456
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> p(n, -1);
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }

  int now = n - 1;
  int cnt = 0;
  while (p[now] != -1) {
    cnt++;
    now = p[now];
  }

  cout << cnt << endl;
}
