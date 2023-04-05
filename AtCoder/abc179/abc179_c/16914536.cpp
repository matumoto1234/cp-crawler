// detail: https://atcoder.jp/contests/abc179/submissions/16914536
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void outputV(vector<ll> v){
  for(ll i=0;i<v.size();i++){
    if(i){
      cout<<' ';
    }
    cout<<v[i];
  }
  cout<<endl;
}

int main(){
  ll n;
  cin>>n;
  vector<ll> list(n+1,0);
  for(ll i=1;i*i<=n;i++){
    for(ll j=i;i*j<=n;j++){
      if(i==j){
        list[i*j]++;
      }else{
        list[i * j] += 2;
      }
    }
  }
  ll sum=0;
  for(ll i=1;i<n;i++){
    sum+=list[i];
  }
  cout<<sum<<endl;
  return 0;
}