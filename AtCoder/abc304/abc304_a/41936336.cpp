// detail: https://atcoder.jp/contests/abc304/submissions/41936336
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> s(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> a[i];
  }

  int min_index = min_element(a.begin(), a.end()) - a.begin();

  for (int i = 0; i < n; i++) {
    int current = i + min_index;
    current %= n;

    cout << s[current] << "\n";
  }
}