// detail: https://atcoder.jp/contests/agc023/submissions/19740420
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = INT64_MAX/2;

ll nCr(ll n,ll r){
  ll res=1;
  for(ll i=1;i<=r;i++){
    res*=(n-i+1);
    res/=i;
  }
  return res;
}

int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  vector<ll> acm(n+2,0);
  acm[n+1]=INF;
  for(int i=0;i<n;i++){
    cin>>a[i];
    acm[i+1]=a[i]+acm[i];
  }

  sort(acm.begin(),acm.end());
  ll ans=0;
  ll prev=acm[0],cnt=1;
  for(int i=1;i<=n+1;i++){
    if(acm[i]==prev) cnt++;
    else{
      if(cnt>=2){
        ans+=nCr(cnt,2);
        cnt=1;
      }
      prev=acm[i];
    }
  }
  cout<<ans<<endl;
}