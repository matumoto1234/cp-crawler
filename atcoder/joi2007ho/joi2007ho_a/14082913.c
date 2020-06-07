// detail: https://atcoder.jp/contests/joi2007ho/submissions/14082913
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, k, max = -1;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> seki(n + 1,0);
  for (int i = 0; i < n;i++){
    cin >> a[i];
    seki[i + 1] = seki[i] + a[i];
  }
  for (int i = k - 1; i < n + 1; i++) {
    if(max<seki[i]-seki[i-k]){
      max = seki[i] - seki[i - k];
    }
  }
  cout << max << endl;
  return 0;
}