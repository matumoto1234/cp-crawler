// detail: https://atcoder.jp/contests/arc091/submissions/15360766
#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n, m;
  cin >> n >> m;
  if(n>1&&m>1){
    cout << (n - 2) * (m - 2) << endl;
  }else{
    if(n==2||m==2){
      cout << 0 << endl;
    }else{
      if(n==1){
        cout << m - 2 << endl;
      }else{
        cout << n - 2 << endl;
      }
    }
  }
  return 0;
}