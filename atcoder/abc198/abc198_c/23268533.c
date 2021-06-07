// detail: https://atcoder.jp/contests/abc198/submissions/23268533
#include <bits/stdc++.h>
using namespace std;
/* ループ処理 0からnまで*/
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  long long R, X, Y;
  cin >> R >> X >> Y;
  double dis2 = sqrt(X * X + Y * Y);
  double cnt = dis2 / R;
  /*   if (dis2 % R == 0)
  {
    cout << cnt << endl;
    return 0;
  } */
  double r;
  if (std::modf(cnt, &r) == 0)
  {
    cout << cnt << endl;
    return 0;
  }
  cout << floor(cnt) + 1 << endl;
  return 0;
}