// detail: https://atcoder.jp/contests/dp/submissions/18404708
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll N, W;
  cin >> N >> W;
  vector<ll> w(N), v(N);
  for (ll i = 0; i < N;i++){
    cin >> w[i] >> v[i];
  }

  
  ll maxv=1e5+1;
  vector<vector<ll>> dp(N+1,vector<ll>(maxv+1,0));
  for(ll j=0;j<=maxv;j++){
    for(ll i=0;i<N;i++){
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
      if(j-v[i]<0){
        continue;
      }
      dp[i+1][j]=max(dp[i+1][j],dp[i][j-v[i]]+w[i]);
    }
  }
  ll ans=0;
  for(ll i=0;i<=N;i++){
    for(ll j=0;j<=maxv;j++){
      //printf("%3lld",dp[i][j]);
      if(dp[i][j]>W){
        continue;
      }
      ans=max(ans,j);
    }
    //cout<<'\n';
  }
  cout<<ans<<endl;
  cout<<dp[3][90]<<endl;

  return 0;
}