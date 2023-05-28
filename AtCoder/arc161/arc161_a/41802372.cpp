// detail: https://atcoder.jp/contests/arc161/submissions/41802372
#include <bits/stdc++.h>
using namespace std;

bool is_m(const vector<int> &a) {
  int n = a.size();
  for (int i = 1; i < n - 1; i += 2) {
    bool valid = a[i - 1] < a[i] and a[i] > a[i + 1];
    if (not valid) {
      return false;
    }
  }

  return true;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &v: a) {
    cin >> v;
  }

  sort(a.begin(), a.end());

  vector<int> b(n);
  for (int i = 0; i <= n / 2; i++) {
    b[i * 2] = a[i];
  }

  int j = 1;
  for (int i = n / 2 + 1; i < n; i++) {
    b[j] = a[i];
    j += 2;
  }

  cout << (is_m(b) ? "Yes" : "No") << endl;
}