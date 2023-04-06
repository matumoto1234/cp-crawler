// detail: https://atcoder.jp/contests/donuts-live2014/submissions/15550357
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin>>n;
  ll ans=0;
  while(n>0){
    if(n%7!=0){
      n--;
      continue;
    }
    ll temp=n;
    bool flg=true;
    while(temp>0){
      if(temp%10>7||temp%10==0){
        flg=false;
        break;
      }
      temp/=10;
    }
    if(flg){
      ans++;
      //cout<<"n="<<n<<endl;
    }
    n--;
  }
  cout<<ans<<endl;
  return 0;
}