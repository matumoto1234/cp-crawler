// detail: https://atcoder.jp/contests/donuts-live2014/submissions/15550582
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n,ans=0;
  cin>>n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  if(n%2!=0){
    cout<<"error"<<endl;
    return 0;
  }
  for(ll i=0;i<n;i++){
    if(i%2==0){
      ans+=a[i+1]-a[i];
    }
  }
  cout<<ans<<endl;
  return 0;
}