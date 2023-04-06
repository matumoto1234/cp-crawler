// detail: https://atcoder.jp/contests/abc048/submissions/15337696
#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, x;
  cin >> N >> x;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int count = 0;
  for (int i = 0; i < N - 1; i++) {
    while (a[i] + a[i + 1] > x) {
      if (a[i + 1] > 0) {
        a[i + 1]--;
        count++;
      }else{
        a[i]--;
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}