// detail: https://atcoder.jp/contests/abc169/submissions/13787181
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long int ans = 1;
  cin >> n;
  vector<long long int> a(n);

  for (int i = 0; i < n;i++){
    cin >> a[i];
    if(a[i]*ans>1000000000000000000){
      cout << -1 << endl;
      return 0;
    }
    ans *= a[i];
  }
  cout << ans << endl;
  return 0;
}