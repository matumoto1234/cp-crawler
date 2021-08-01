// detail: https://atcoder.jp/contests/arc119/submissions/24724616
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = INT64_MAX/2;


vector<ll> as;
ll swap_query(ll sum,ll i,ll j){
  if(!(0<=i&&i<(int)as.size())) return INF;
  if(!(0<=j&&j<(int)as.size())) return INF;
  
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
  
  if(n==2){
    cout<<ans<<endl;
    return 0;
  }
  
  if(n<=5000){
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        ans=min(ans,swap_query(sum,i,j));
        ans=min(ans,swap_query(sum,i,j+1));
        ans=min(ans,swap_query(sum,i+1,j));
        ans=min(ans,swap_query(sum,i+1,j+1));
      }
    }
    cout<<ans<<endl;
    return 0;
  }
  
  sort(bs.rbegin(),bs.rend());
  for(int i=0;i<(int)bs.size();i++){
    int idx=bs[i].second;
    for(ll j=i+1;j*j<=(int)bs.size();j++){
      int idx2=bs[j].second;
      ans=min(ans,swap_query(sum,idx,idx2));
      ans=min(ans,swap_query(sum,idx,idx2+1));
      ans=min(ans,swap_query(sum,idx+1,idx2));
      ans=min(ans,swap_query(sum,idx+1,idx2+1));
    }
  }
  
  for(int i=0;i<(int)bs.size();i++){
    int idx=bs[i].second;
    for(ll j=bs.size()-1;j*j>(int)bs.size();j++){
      if(i==j) continue;
      int idx2=bs[j].second;
      ans=min(ans,swap_query(sum,idx,idx2));
      ans=min(ans,swap_query(sum,idx,idx2+1));
      ans=min(ans,swap_query(sum,idx+1,idx2));
      ans=min(ans,swap_query(sum,idx+1,idx2+1));
    }
  }
  
  for(int i=0;i<(int)bs.size();i++){
    int idx=bs[i].second;
    for(ll j=0;j*j*j<i;j++){
      int idx2=bs[j].second;
      ans=min(ans,swap_query(sum,idx,idx2));
      ans=min(ans,swap_query(sum,idx,idx2+1));
      ans=min(ans,swap_query(sum,idx+1,idx2));
      ans=min(ans,swap_query(sum,idx+1,idx2+1));
    }
  }
  
  
  cout<<ans<<endl;
}