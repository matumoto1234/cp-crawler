// detail: https://atcoder.jp/contests/arc108/submissions/18258576
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdint>
#include<vector>
using namespace std;
using ll = long long;

int main(){
  ll n,m;
  cin>>n>>m;
  vector<ll> yaku;
  for(ll i=1;i*i<=m;i++){
    if(m%i==0){
      yaku.push_back(i);
    }
  }
  ll l=(ll)yaku.size();
  for(ll i=0;i<l;i++){
    ll a,b;
    a=yaku[i];
    b=m/yaku[i];
    if(a+b==n&&a*b==m){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}