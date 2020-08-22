// detail: https://atcoder.jp/contests/abc130/submissions/16165907
#include<bits/stdc++.h>
using namespace std;
int main(){
  int W,H,x,y;
  cin>>W>>H>>x>>y;
  double s=(double)(W*H);
  cout<<fixed<<setprecision(10);
  cout<<s/2.0<<" "<<((double)W/2.0==(double)x&&(double)W/2.0==(double)y)<<endl;
  return 0;
}