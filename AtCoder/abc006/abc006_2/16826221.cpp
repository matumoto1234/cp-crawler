// detail: https://atcoder.jp/contests/abc006/submissions/16826221
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p = 10007;

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
  vector<ll> a(n+1,0);
  a[2]=1;
  for(ll i=3;i<n;i++){
    a[i]=a[i-1]+a[i-2]+a[i-3];
    a[i]%=p;
  }
  cout<<a[n-1]<<endl;
  return 0;
}