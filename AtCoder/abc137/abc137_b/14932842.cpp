// detail: https://atcoder.jp/contests/abc137/submissions/14932842
#include<bits/stdc++.h>
using namespace std;
int main(){
  int k,x;
  cin >> k >> x;
  k--;
  for (int i = x - k; i < x+k;i++){
    cout << i << " " << flush;
  }
  cout << x + k << endl;
  return 0;
}