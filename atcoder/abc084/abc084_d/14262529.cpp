// detail: https://atcoder.jp/contests/abc084/submissions/14262529
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int main() {
  int q;
  cin >> q;
  vector<int> l(MAX), r(MAX);
  vector<int> a(MAX, 0);
  vector<int> prime(MAX, 1);

  for (int i = 2; i <= MAX; i++) {
    if (prime[i] == 1) {
      for (int j = i * 2; j <= MAX; j += i) {
        prime[j] = 0;
      }
    }
  }

  for (int i = 0; i < q; i++) {
    cin >> l[i] >> r[i];
  }

  for (int i = 0; i < MAX; i++) {
    if (i % 2 == 0)
      continue;
    if (prime[i] == 1 && prime[(i + 1) / 2] == 1) {
      a[i] = 1;
    }
  }
  vector<int> s(MAX + 1, 0);
  for (int i = 0; i < MAX; i++) {
    s[i + 1] += s[i] + a[i];
  }

  for (int i = 0; i < q; i++) {
    cout << s[r[i] + 1] - s[l[i]] << endl;
  }
  return 0;
}