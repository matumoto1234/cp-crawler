// detail: https://atcoder.jp/contests/arc121/submissions/24721147
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin>>n;
  vector<ll> as(n);
  for(auto &a:as) cin>>a;
  
  if(n%2){
    as.emplace_back(0);
    n++;
  }
  sort(as.begin(),as.end());
  
  constexpr ll INF = INT64_MAX/2;
  ll ma=-INF;
  ll mi=INF;
  
  
  for(int i=0;i<n/2;i++){
    ll v=as[i]+as[n-1-i];
    ma=max(ma,v);
    mi=min(mi,v);
  }
  cout<<ma-mi<<endl;
}