// detail: https://atcoder.jp/contests/abc036/submissions/21124841
#include <bits/stdc++.h>
using namespace std;

template <typename T1,typename T2>
T1 ceilDiv(T1 a,T2 b){
  return (a+(b-1))/b;
}

int main(){
  int a,b;
  cin>>a>>b;
  cout<<ceilDiv(b,a)<<endl;
  return 0;
}