// detail: https://atcoder.jp/contests/abc173/submissions/14966448
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while(1){
    n -= 1000;
    if(n<1000){
      break;
    }
  }
  if(n==0){
    cout << 0 << endl;
  }else{
    cout << 1000 - n << endl;
  }
  return 0;
}