// detail: https://atcoder.jp/contests/abc067/submissions/15332520
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  for (int i = 0; i < n;i++){
    cin >> l[i];
  }
  sort(l.rbegin(), l.rend());
  int sum = 0;
  for (int i = 0; i < k;i++){
    sum += l[i];
  }
  cout << sum << endl;
  return 0;
}