// detail: https://atcoder.jp/contests/abc078/submissions/16297220
#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z;
  cin>>x>>y>>z;
  x-=z;
  cout<<x/(y+z)<<endl;
  return 0;
}