// detail: https://atcoder.jp/contests/agc034/submissions/17556243
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  string s;
  cin>>s;

  vector<ll> cntA(3,0);
  vector<ll> cntBC(3,0);
  for(ll i=0;i<s.size();i++){
    if(s[i]=='A'){
      cntA[i%3]++;
    }
    if(i==s.size()-2){
      continue;
    }
    if(s[i+1]=='B'&&s[i+2]=='C'){
      cntBC[i%3]++;
    }
  }
  ll ans=0;
  for(ll i=0;i<3;i++){
    ll temp=min(cntA[i],cntBC[i]);
    ans+=(1+temp)*temp/2;
    //printf("A=%lld BC=%lld\n",cntA[i],cntBC[i]);
  }
  cout<<ans<<endl;
  return 0;
}