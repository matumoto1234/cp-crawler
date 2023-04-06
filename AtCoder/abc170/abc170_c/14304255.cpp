// detail: https://atcoder.jp/contests/abc170/submissions/14304255
#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, n;
  int ans, min;
  cin >> x >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  ans = 10000;
  min = 10000;
  bool flg;
  for (int i = 1; i <= 100;i++){
    flg = false;
    for (int j = 0; j < n;j++){
      if(i==p[j]){
        flg = true;
        break;
      }
    }
    if(flg){
      continue;
    }else{
      if (min > abs(x - i)) {
        min = abs(x - i);
        ans = i;
      }
    }
  }
  cout << ans << endl;
  return 0;
}