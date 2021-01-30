// detail: https://atcoder.jp/contests/abc190/submissions/19818307
#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
using cint = boost::multiprecision::cpp_int;

ll n;
cint N;

cint sum(cint l,cint r){
  cint res=(l+r)*(r-l+1)/2;
  return res;
}

bool solve(ll l,ll r){
  cint S=sum(l,r);
  if(S<=N){
    return true;
  }else{
    return false;
  }
}

int main(){
  cin>>n;
  N=n;
  ll ans=0;
  const ll limit = 1000000;
  for(ll left=-limit;left<=n;left++){
    ll right;
    ll l=left;
    ll r=limit;
    while(abs(r-l)>1){
      //if(left==0) cerr<<"l:"<<l<<" r:"<<r<<endl;
      ll mid=(l+r)/2;
      if(solve(left,mid)){
        l=mid;
      }else{
        r=mid;
      }
    }
    if(sum(left,l)==N) ans++;
  }
  cout<<ans<<endl;
}