// detail: https://atcoder.jp/contests/abc185/submissions/18722968
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  vector<int> a(4);
  for(int i=0;i<4;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  cout<<a[0]<<endl;
  return 0;
}
