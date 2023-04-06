// detail: https://atcoder.jp/contests/donuts-live2014/submissions/15550252
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin>>n;
  ll ans=n/70*8;
  ll temp=n%70;
  while(temp>0){
    if(temp%7!=0){
      temp--;
      continue;
    }
    ll temp2=temp;
    bool flg=true;
    while(temp2>0){
      if(temp2%10>7){
        flg=false;
        break;
      }
      temp2/=10;
    }
    if(flg){
      ans++;
      //cout<<"temp="<<temp<<endl;
    }
    temp--;
  }
  cout<<ans<<endl;
  return 0;
}