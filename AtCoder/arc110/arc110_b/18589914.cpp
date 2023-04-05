// detail: https://atcoder.jp/contests/arc110/submissions/18589914
#include <algorithm>
#include <iostream>
#include <vector>
#include<string>
using namespace std;
using ll = long long;

ll llpow(ll a,ll e){
  if(e==0){
    return 1LL;
  }
  if(e%2==0){
    ll res=llpow(a,e/2);
    return res*res;
  }else{
    ll res=llpow(a,e-1)*a;
    return res;
  }
}

int main() {
  ll n;
  string t;
  cin >> n>>t;
  string s;
  ll counter=0;
  while(s.size()<=t.size()){
    s+="110";
    counter++;
  }
  ll cnt=0;
  ll last=0;
  for(int i=0;i<=s.size()-t.size();i++){
    int idx=s.find(t,i);
    if(idx!=string::npos&&last!=idx){
      cnt++;
      last=idx;
    }
  }
  //cerr<<cnt<<' '<<last<<endl;
  last+=n;
  ll l=s.size();
  ll N=llpow(10LL,10LL)-(counter-1);
  //ll N=4LL-(counter-1);
  ll ans=N*cnt;
  cout<<ans<<endl;
  return 0;
}