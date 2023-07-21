// detail: https://atcoder.jp/contests/abc012/submissions/43788757
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int sum = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      sum += i * j;
    }
  }

  int prod = sum - n;
  vector<pair<int, int>> ans;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      if (i * j == prod) {
        ans.push_back(pair(i, j));
      }
    }
  }

  sort(ans.begin(), ans.end());

  for (auto [i, j]: ans) {
    cout << i << " x " << j << endl;
  }
}
