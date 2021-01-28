// detail: https://atcoder.jp/contests/abc174/submissions/19738935
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n,d;
  cin>>n>>d;
  ll ans=0;
  for(int i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    if(x*x+y*y<=d*d) ans++;
  }
  cout<<ans<<endl;
}