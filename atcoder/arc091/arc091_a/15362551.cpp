// detail: https://atcoder.jp/contests/arc091/submissions/15362551
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,M;
  cin >> N >> M;
  long long ans =  (N-2)*(M-2);
  
  if(N==1&&M==1){
    cout << 1<<endl;
  }
  else if(N==1){
  cout << M-2<<endl;
  }
  else if(M==1){
  cout << N-2<<endl;
  }
  else if(ans<0){
  cout << 0 <<endl;
    }
  else{
  cout << ans <<endl;
  }
}
