// detail: https://atcoder.jp/contests/chokudai_S002/submissions/14712155
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n;i++){
    cin >> a[i] >> b[i];
    if(a[i]==b[i]){
      cout << -1 << endl;
    }
    else{
      cout << abs(a[i] - b[i]) << endl;
    }
  }
  return 0;
}