// detail: https://atcoder.jp/contests/dp/submissions/17609024
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll N,W;
  cin>>N>>W;
  vector<ll> w(N),v(N);
  for(ll i=0;i<N;i++){
    cin>>w[i]>>v[i];
  }
  vector<vector<ll>> dp(N+1,vector<ll>(W+1,0));
  for(ll j=0;j<=W;j++){
    for(ll i=0;i<N;i++){
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
      if(j-w[i]<0){
        continue;
      }
      dp[i+1][j]=max(dp[i+1][j],dp[i][j-w[i]]+v[i]);
    }
  }
  cout<<dp[N][W]<<endl;
  return 0;
}