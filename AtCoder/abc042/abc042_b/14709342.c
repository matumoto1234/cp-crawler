// detail: https://atcoder.jp/contests/abc042/submissions/14709342
#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, L;
  cin >> N >> L;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
    sort(S[i].begin(), S[i].end());
  }
  sort(S.begin(), S.end());
  for (int i = 0; i < N; i++) {
    cout << S[i] << flush;
  }
  cout << endl;
  return 0;
}