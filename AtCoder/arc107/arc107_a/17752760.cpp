// detail: https://atcoder.jp/contests/arc107/submissions/17752760
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p = 998244353;

ll modPow(ll a,ll e){
  cout<<a<<' '<<e<<endl;
  if(e==0){
    return 1LL;
  }
  if(e%2==0){
    ll res=modPow(a,e/2)%p;
    return (res*res)%p;
  }else{
    ll res=modPow(a,e-1)*a;
    return res%p;
  }
}

int main(){
  ll a,b,c;
  cin>>a>>b>>c;
  ll sum=0;


  a=(1+a)*a/2LL;
  b=(1+b)*b/2LL;
  c=(1+c)*c/2LL;
  a%=p;
  b%=p;
  c%=p;

  sum=(((a*b)%p)*c)%p;
  cout<<sum<<endl;

  return 0;
}