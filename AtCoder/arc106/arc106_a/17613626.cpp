// detail: https://atcoder.jp/contests/arc106/submissions/17613626
#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll loop_pow(ll a,ll e){
  if(e==0){
    return 1LL;
  }
  if(e%2==0){
    ll res=loop_pow(a,e/2);
    return res*res;
  }
  return a*loop_pow(a,e-1);
}

int main(){
  ll n;
  cin>>n;
  bool flg=false;
  for(ll i=0;i<38;i++){
    for(ll j=0;j<25;j++){
      ll a=loop_pow(3,i);
      ll b=loop_pow(5,j);
      if(a+b>n){
        break;
      }
      if(a+b==n){
        flg=true;
        cout<<i<<' '<<j<<endl;
        break;
      }
    }
    if(flg){
      break;
    }
  }

  if(!flg){
    cout<<-1<<endl;
  }
  return 0;
}