// detail: https://atcoder.jp/contests/arc111/submissions/19294728
#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
using cint = boost::multiprecision::cpp_int;

cint modPow(cint a,cint e,cint p){
  if(e==0) return 1;
  if(e%2==0){
    cint res=modPow(a,e/2,p);
    return (res*res)%p;
  }
  cint res=modPow(a,e-1,p)*a;
  res%=p;
  return res;
}

int main(){
  cint n,m;
  cin>>n>>m;
  cint ans=modPow(10,n,m*m);
  ans/=m;
  cout<<ans%m<<endl;
}