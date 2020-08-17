// detail: https://atcoder.jp/contests/abc070/submissions/16006672
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<min(0,min(b,d)-max(c,a))<<endl;
  return 0;
}