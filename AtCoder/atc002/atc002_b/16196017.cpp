// detail: https://atcoder.jp/contests/atc002/submissions/16196017
#include<btis/stdc++.h>
using namespace std;
using ll = long long;

ll modP(ll n,ll m,ll p){
  if(p==0){
    return 1LL;
  }
  if(p%2==0){
    ll ret=modP(n,m,p/2);
    ret%=m;
    return ret*ret;
  }else{
    ll ret=modP(n,m,p-1);
    ret%=m;
    return ret;
  }
}

int main(){
  ll n,m,p;
  cin>>n>>m>>p;
  cout<<modP(n,m,p)<<endl;
  return 0;
}