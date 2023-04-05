// detail: https://atcoder.jp/contests/abc019/submissions/13361425
#include<bits/stdc++.h>
using namespace std;
int main(){
  vector a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(a.begin(),a.end());
  cout<<a[1]<<endl;
  return 0;
}