// detail: https://atcoder.jp/contests/abc084/submissions/17387403
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isNum(ll);
bool isPrime(ll);


int main(){

  // preparation

  vector<ll> count(1e5+1,0);
  for(ll i=2;i<=1e5;i++){
    if(i%2&&isNum(i)){
      count[i]++;
    }
    count[i]+=count[i-1];
  }

  ll q;
  cin>>q;
  for(ll i=0;i<q;i++){
    ll l,r;
    cin>>l>>r;
    l--;
    cout<<count[r]-count[l]<<'\n';
  }
  return 0;
}



bool isNum(ll n){
  if(isPrime(n)&&isPrime((n+1)/2)) return true;
  return false;
}

bool isPrime(ll n){
  bool flg=true;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      flg=false;
      break;
    }
  }
  return flg;
}