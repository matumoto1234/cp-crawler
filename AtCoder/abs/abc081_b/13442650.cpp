// detail: https://atcoder.jp/contests/abs/submissions/13442650
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, min = INT_MAX, cnt;
  cin >> n;
  vector<int> a(n);
  
  for(int i = 0; i < n; i++){
    cin >> a[i];
    cnt = 0;
    while(a[i] % 2 == 0){
      a[i] /= 2;
      cnt++;
    }
    if(cnt < min){
      min = cnt;
    }
  }
  return 0;
}