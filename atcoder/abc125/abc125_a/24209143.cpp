// detail: https://atcoder.jp/contests/abc125/submissions/24209143
#include <bits/stdc++.h>
using namespace std;
/* ループ処理 0からnまで*/
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int A, B, T;
  cin >> A >> B >> T;
  int sum = 0;
  if (A > T)
  {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= (double)T + 0.5; i += A)
  {
    sum += B;
  }
  cout << sum << endl;
  return 0;
}