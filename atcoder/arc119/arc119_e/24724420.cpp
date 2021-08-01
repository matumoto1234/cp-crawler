// detail: https://atcoder.jp/contests/arc119/submissions/24724420
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<ll> as;
ll swap_query(ll sum,ll i,ll j){
  if(i-1>=0) sum-=abs(as[i]-as[i-1]);
  if(j+1<(int)as.size()) sum-=abs(as[j]-as[j+1]);
  swap(as[i],as[j]);
  if(i-1>=0) sum+=abs(as[i]-as[i-1]);
  if(j+1<(int)as.size()) sum+=abs(as[j]-as[j+1]);
  swap(as[i],as[j]);
  return sum;
}

int main(){
  int n;
  cin>>n;
  as.resize(n);
  for(auto &a:as) cin>>a;
  
  
  vector<pair<ll,int>> bs(n-1);
  for(int i=0;i<n-1;i++){
    int a=as[i],na=as[i+1];
    auto &[b,idx]=bs[i];
    b=abs(a-na);
    idx=i;
  }
  
  ll sum=0;
  for(auto [b,idx]:bs){
    sum+=b;
  }
  ll ans=sum;
  
  sort(bs.rbegin(),bs.rend());
  for(int i=0;i<n;i++){
    int idx=bs[i].second;
    for(ll j=0;j*j<=n;j++){
      if(i==j) continue;
      int idx2=bs[j].second;
      ans=min(ans,swap_query(sum,idx,idx2));
      ans=min(ans,swap_query(sum,idx,idx2+1));
      ans=min(ans,swap_query(sum,idx+1,idx2));
      ans=min(ans,swap_query(sum,idx+1,idx2+1));
    }
  }
  cout<<ans<<endl;
}