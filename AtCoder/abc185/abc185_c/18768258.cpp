// detail: https://atcoder.jp/contests/abc185/submissions/18768258
#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using cpp_int = boost::multiprecision::cpp_int;

cpp_int fact(cpp_int a){
  if(a==1) return 1;
  return a*fact(a-1);
}

cpp_int comb(cpp_int N,cpp_int R){
  R=fact(R);
  cpp_int c=1;
  for(int i=0;i<11;i++){
    c*=N-i;
  }
  N=c;
  return N/R;
}

int main(){
  cpp_int L;
  cin>>L;
  cout<<comb(L-1,11)<<endl;
  return 0;
}
