// detail: https://atcoder.jp/contests/tokiomarine2020/submissions/14229525
#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, v, w, t;
  cin >> a >> v >> b >> w >> t;
  //cout << a << v << b << w << t << endl;
  if(a<=b){
    int tmp1 = t * v + a;
    int tmp2 = t * w + b;
    if(tmp1>=tmp2){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }else{
    int tmp1 = -1 * (t * v) + a;
    int tmp2 = -1 * (t * w) + b;
    if(tmp1<=tmp2){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  

  return 0;
}