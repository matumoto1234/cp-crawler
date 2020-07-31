// detail: https://atcoder.jp/contests/donuts-live2014/submissions/15550037
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin>>n;
  ll ans=n/70*8;
  ll temp=n%70;
  while(temp>0){
    ll tmp=temp;
    bool flg=true;
    while(tmp>0){
      if(tmp%10>8){
        flg=false;
        break;
      }
      tmp/=10;
    }
    if(flg){
      ans++;
    }
    temp-=7;
  }
  cout<<ans<<endl;
  return 0;
}